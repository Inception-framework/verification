# Authors: Giovanni Camurati, Nassim Corteggiani
if [ "$#" != 1 ]; then
  echo "Missing arguments ..."
  echo "$0 <version file>"
  exit
fi

vfile=$1

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd ..
echo "Save current version info in $vfile" | tee $vfile
echo "Inception" | tee -a $vfile
git branch | tee -a $vfile
git log -1 --format="%H" | tee -a $vfile
git submodule status | tee -a $vfile
cd Samples
git submodule status | tee -a $vfile
cd $DIR

