# Authors: Giovanni Camurati, Nassim Corteggiani
# check that current changes to the test
# do not break the system
for i in $(seq 0 50); do
  # before
  git stash;
  rm -rf test;
  ./generator.py -s $i -c False;
  ./verify.py -s $i -c True | \
  grep -E 'PASSED|failed' > before;
  
  # after
  git stash pop;
  rm -rf newmain;
  rm -rf results;
  ./generator.py -s $i -c False -o tests/newmain; \
  ./verify.py -c True -i newmain -o tests/ciao/results| \
  grep -E 'PASSED|failed' > after;
  
  # check
  echo "TEST $i"
  if [ "$(diff -r before after)" ]
  then
    echo "ERROR $i"
    exit 1
  fi
  
done;
rm -rf test
rm -rf tests/newmain
rm -rf tests/ciao/results
rm -rf after
rm -rf before

