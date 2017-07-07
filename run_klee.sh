#!/bin/sh

if [ "$#" != 1 ]; then
  echo "Missing arguments ..."
  echo "$0 <ITERATION_NUMBER>"
  exit
fi

run_klee() {

  arg1=$1

  # Remove old dump file
  rm registers.dump >&-

  klee -search=dfs main${arg1}_merged.bc  >&-

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

  cat registers.dump | awk 'BEGIN {for(i=1; i<=6; i++){getline;}} \

  {print $3; getline; print $2; for(i=1; i<=4; i++) \

  {getline;}}' > reg_diff_klee$1.log
}

main() {

  echo "-----------------[KLEE]------------------------"

  #Source code directory
  cd main

  #For each test run
  for i in `seq 0 $1`;
  do
    echo "[RUNNING]\t Test ${i} is running ..."
    run_klee ${i}
    echo "Done"

    echo "[PARSER]\t Parsing dump ${i} ..."
    extract_dump_info $i
    echo "Done"
  done

  cd ..

  echo "-----------------------------------------------"
  exit 0
}

main $1
