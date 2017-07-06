#!/bin/sh
cd main

rm registers$1.dump
cp ../../Samples/lpc1800-demos/config.json .
klee -search=dfs main$1_merged.bc
rm -rf klee-*
cat registers$1.dump | awk 'BEGIN {for(i=1; i<=6; i++){getline;}} \
{print $3; getline; print $2; for(i=1; i<=4; i++) \
{getline;}}' > reg_diff_klee$1.log
DIFFERENCE=$(diff reg_diff$1.log reg_diff_klee$1.log)
if [ "$DIFFERENCE" != "" ]; then
  echo "TEST FAILED!! registers differ:"
  echo $DIFFERENCE
  cd ..
  exit 1
fi 
cd ..
echo "TEST PASSED"
exit 0
