set -o nounset
set -o errexit
set -o pipefail

ROOT_DIR=$(realpath $(dirname $(dirname $0)))

MAIN_CXX=$ROOT_DIR/src/main.cxx
NBODY_CXX=$ROOT_DIR/src/nbody.cxx

NPARTICULES=$(cat $ROOT_DIR/input/nparticules)
NTIMES=$(cat $ROOT_DIR/input/ntimes)

script_name=$(basename $0)
script_name_without_ext=${script_name%.sh}
RESULT_DIR="$ROOT_DIR/out/$script_name_without_ext"

mkdir -p $RESULT_DIR
cd $RESULT_DIR
