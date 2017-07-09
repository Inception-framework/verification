#!/bin/sh

if [ "$#" != 2 ]; then
  echo "Missing arguments ..."
  echo "$0 <ITERATION_NUMBER> <folder>"
  exit
fi

run_klee() {

  arg1=$1

  # Remove old dump file
  rm registers.dump >&-

  # Load the configuration file
  cp ../../Samples/lpc1800-demos/config.json .

  # Remove old log
  rm -rf klee-* >&-

  # Run klee
  klee -search=dfs main${arg1}_merged.bc  >&-
  if [ $? != 0 ]; then
          printf "---> failed"
          exit 1;
  fi

  # Backup dump files
  cp registers.dump ${arg1}.klee.dump
  if [ $? != 0 ]; then
          printf "Klee encountered an error ...\n"
          exit 1;
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
}

main() {

  folder=$2
  DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
  
  echo "-----------------[KLEE]------------------------"

  #Source code directory
  cd $folder

  #For each test run
  for i in `seq 0 $(($1-1))`;
  do
    echo "[RUNNING]\t Test ${i} is running ..."
    run_klee ${i}
    echo "Done"

    echo "[PARSER]\t Parsing dump ${i} ..."
    extract_dump_info $i
    echo "Done"
  done

  cd $DIR

  echo "-----------------------------------------------"
  exit 0
}

main $1 $2
