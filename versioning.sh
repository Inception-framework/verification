# Authors: Giovanni Camurati, Nassim Corteggiani
if [ "$#" != 1 ]; then
  echo "Missing arguments ..."
  echo "$0 <version file>"
  exit
fi

vfile=$1

ANALYZER=../analyzer
TRANSLATOR=../translator
RTDEBUGGERDRIVER=../rt-debugger-driver
VERIFICATION="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

echo "Save current version info in $vfile" | tee $vfile
echo "Inception-framework" | tee -a $vfile
echo "" | tee -a $vfile
echo "analyzer" | tee -a $vfile
cd $ANALYZER
git branch | tee -a $vfile
git log -1 --format="%H" | tee -a $vfile

echo "" | tee -a $vfile
echo "translator" | tee -a $vfile
cd $TRANSLATOR
git branch | tee -a $vfile
git log -1 --format="%H" | tee -a $vfile

echo "" | tee -a $vfile
echo "rt-debugger-driver" | tee -a $vfile
cd $RTDEBUGGERDRIVER
git branch | tee -a $vfile
git log -1 --format="%H" | tee -a $vfile

echo "" | tee -a $vfile
echo "verification" | tee -a $vfile
cd $VERIFICATION
git branch | tee -a $vfile
git log -1 --format="%H" | tee -a $vfile

