# Authors: Giovanni Camurati, Nassim Corteggiani

if [ "$#" != 2 ]; then
  echo "./simple_regression <max seed>" 
fi

rm log
for i in $(seq 0 $1); do
  ./generator.py -s $i -c True
  if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
  fi
  printf "%s\n" "--> ok"
  ./verify.py -c True | grep -E 'PASSED|test failed' > verif
  if [ $? != 0 ]; then
	printf "%s\n" "--> failed"
	exit 1;
  fi
  printf "%s\n" "--> ok"
  while read -r line; do
    echo "SEED $i $line" >> log
  done < verif;
done;

rm verif
cat log | grep 'failed' > failed
cat log | grep 'PASSED' > passed
echo "$(wc -l passed)"
echo "$(wc -l failed)"
cat failed
