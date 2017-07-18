#!/bin/sh
# Authors: Giovanni Camurati, Nassim Corteggiani
filter_reglist="a"
while getopts ":t:f:" opt; do
  case $opt in
    t)
      test_name=$OPTARG
      echo "test_name = $test_name"
      ;;
    f)
      filter_reglist=$OPTARG
      echo "filter_reglist = $filter_reglist"
      ;;
    \?)
      echo "-$OPTARG does not exist"
      exit 1
      ;;
    :)
      echo "-$OPTARG requires an argument"
      exit 1
      ;;
  esac
done
if [ -z "$test_name" ]
then
   echo "--> $test_name.failed ci.sh wrong arguments"
   echo "usage:"
   echo "./ci.sh -t <test_name>"
   exit 0
fi

# set dirs
tests=ci/tests/$test_name
results=ci/results/$test_name

# clean up
rm ci/$test_name.log
rm ci/$test_name.failed
rm ci/$test_name.passed
rm ci/$test_name.cpsr_not_implemented
#rm ci/$test_name.verif
rm -rf $results
mkdir $results
rm -rf klee*

# launch the verify script and dump results
./verify.py -c True \
            -i $tests \
            -o $results \
            -f $filter_reglist \
            | grep -E 'PASSED|test failed|fracture failed|llvm-as' > ci/$test_name.log
if [ $? != 0 ]; then
      printf "%s\n" "--> failed"
      exit 1;
fi
printf "%s\n" "--> ok"

#while read -r line; do
#  echo "SEED $i $line" >> ci/$test_name.log
#done < verif;

echo ""
echo "-----------------------------"
echo "-- Regression results -------"
echo "-----------------------------"
cat ci/$test_name.log | grep 'failed' > ci/$test_name.failed
cat ci/$test_name.log | grep 'PASSED' > ci/$test_name.passed
cat ci/$test_name.failed | grep 'fracture' > ci/$test_name.failed_fracture
cat ci/$test_name.failed | grep 'llvm-as' > ci/$test_name.failed_llvm-as
cat ci/$test_name.failed | grep 'CPSR' > ci/$test_name.cpsr_not_implemented
echo "$(wc -l ci/$test_name.passed)"
echo "$(wc -l ci/$test_name.failed)"
echo "    $(wc -l ci/$test_name.failed_fracture)"
echo "    $(wc -l ci/$test_name.failed_llvm-as)"
echo "    $(wc -l ci/$test_name.cpsr_not_implemented)"
cat ci/$test_name.failed

exit $(wc -l ci/$test_name.failed)
