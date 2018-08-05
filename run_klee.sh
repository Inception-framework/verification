#!/bin/bash

if [ "$#" != 2 ]; then
  echo "Missing arguments ..."
  echo "$0 <ITERATION_NUMBER> <folder>"
  exit
fi

run_klee() {

  arg1=$1

  # Remove old dump file
  #rm registers.dump >&-
  #rm stack.dump >&-

  # Load the configuration file
  #cp $DIR/../Samples/lpc1800-demos/config.json .
  cp $DIR/config.json .
  sed -i -r "s/prova.elf/main${arg1}.elf/g" config.json

  # Remove old log
  rm -rf klee-* >&-

  # Run klee
  klee -search=dfs main${arg1}_merged.bc 2>&1 >/dev/null
  if [ $? != 0 ]; then
          printf "---> test $arg1 running klee failed"
          exit 1;
  fi

  # Backup dump files
  cp registers.dump ${arg1}.klee.dump
  if [ $? != 0 ]; then
          printf "Klee encountered an error ...\n"
          exit 1;
  fi
  if [ -f stack.dump ]; then
  cat stack.dump | grep value | tr ':' '\n' | sed -r 's/^[[:space:]]//g' > stack_klee${arg1}.dump
  fi
}

extract_dump_info() {

  cat registers.dump | awk '{ \
    print $1; \
    getline; \
    getline; \
    print $2; \
    for(i=1; i<=4; i++) \
      {getline;}}' > reg_diff_klee$1.log

  if [ -f stack_klee$1.dump ]; then
  cat stack_klee$1.dump  >> reg_diff_klee$1.log
  fi
}

main() {

  folder=$2
  DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
  
  echo "-----------------[KLEE]------------------------"

  #Source code directory
  cd $folder

  #For each test run
  #for i in `seq 0 $(($1-1))`;
  #do
    echo "[RUNNING]\t Test $1 is running ..."
    run_klee $1
    echo "Done"

    echo "[PARSER]\t Parsing dump $1 ..."
    extract_dump_info $1
    echo "Done"
  #done

  cd $DIR

  echo "-----------------------------------------------"
  exit 0
}

main $1 $2
