#!/bin/sh
cd main

for i in $(seq 0 $(expr $(cat Ntests) - 1)); do 

  rm registers.dump
  cp ../../Samples/lpc1800-demos/config.json .
  klee -search=dfs main${i}_merged.bc
  rm -rf klee-*
  cat registers.dump | awk 'BEGIN {for(i=1; i<=6; i++){getline;}} \
  {print $3; getline; print $2; for(i=1; i<=4; i++) \
  {getline;}}' > reg_diff_klee$i.log
  DIFFERENCE=$(diff reg_diff$i.log reg_diff_klee$i.log)
  if [ "$DIFFERENCE" != "" ]; then
    echo "TEST FAILED!! registers differ:"
    echo $DIFFERENCE
    cd ..
    exit 1
  fi 
  echo "TEST PASSED"

done

cd ..
exit 0
