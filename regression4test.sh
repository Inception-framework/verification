# Authors: Giovanni Camurati, Nassim Corteggiani
# check that current changes to the test
# do not break the system
for i in $(seq 0 50); do
  # before
  git stash > /dev/null;
  rm -rf main;
  ./generator.py -s $i -c False > /dev/null;
  ./verify.py -s $i -c True | \
  grep -E 'PASSED|failed' > main/before;
  
  # after
  git stash pop > /dev/null;
  rm -rf newmain;
  ./generator.py -s $i -c False -f newmain > /dev/null; \
  ./verify.py -s $i -c True -f newmain| \
  grep -E 'PASSED|failed' > newmain/after;
  
  # check
  echo "TEST $i"
  if [ "$(diff -r main/before newmain/after)" ]
  then
    echo "ERROR $i"
    exit 1
  fi
 
done;
rm -rf main
rm -rf newmain
