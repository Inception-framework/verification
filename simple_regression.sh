# Authors: Giovanni Camurati, Nassim Corteggiani

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
echo "$(wc -l passed)"
echo "$(wc -l failed)"
cat failed
