set -o nounset
set -o errexit
set -o pipefail

NPARTICULES=`cat input/nparticules`
NTIMES=`cat input/ntimes`

RESULT_DIR="out-${0%.sh}"

mkdir -p $RESULT_DIR
