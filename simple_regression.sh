#!/bin/sh
# Authors: Giovanni Camurati, Nassim Corteggiani

#min_seed=0
#max_seed=4
#tests_per_instruction=2
#no_generate=false
#j=1
#folder=simple_regression
#
#while getopts ":m:M:N:nj:f:" opt; do
#  case $opt in
#    m)
#      min_seed=$OPTARG
#      echo "min_seed = $min_seed"
#      ;;
#    M)
#      max_seed=$OPTARG
#      echo "max_seed = $max_seed"
#      ;;
#    N)
#      tests_per_instruction=$OPTARG
#      echo "tests_per_instruction = $tests_per_instruction"
#      ;;
#    n)
#      no_generate=true
#      echo "no_generate = $no_generate"
#      ;;
#    j)
#      j=$OPTARG
#      echo "j (number of processes) = $j"
#      ;;
#    f)
#      folder=$OPTARG
#      echo "folder = $folder"
#      ;;
#    \?)
#      echo "-$OPTARG does not exist"
#      exit 1
#      ;;
#    :)
#      echo "-$OPTARG requires an argument"
#      exit 1
#      ;;
#  esac
#done
#
#exit 0

if [ "$#" != 3 ]; then
  echo "./simple_regression <min seed> <max seed> <tests per instruction>" 
fi

rm log
rm failed
rm passed
rm -rf simple_regression

for i in $(seq $1 $2); do
  ./generator.py -s $i -c True -o simple_regression/test_cases_$i -N $3
  if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
  fi
  printf "%s\n" "--> ok"
  ./verify.py -c True \
              -i simple_regression/test_cases_$i \
              -o simple_regression/test_results_$i \
              | grep -E 'PASSED|test failed|fracture failed' > verif
  if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
  fi
  printf "%s\n" "--> ok"
  while read -r line; do
    echo "SEED $i $line" >> log
  done < verif;
done;

#rm verif
echo ""
echo "-----------------------------"
echo "-- Regression results -------"
echo "-----------------------------"
cat log | grep 'failed' > failed
cat log | grep 'PASSED' > passed
cat failed | grep 'fracture' > failed_fracture
cat failed | grep 'CPSR' > cpsr_not_implemented
echo "$(wc -l passed)"
echo "$(wc -l failed)"
echo "    $(wc -l failed_fracture)"
echo "    $(wc -l cpsr_not_implemented)"
cat failed
