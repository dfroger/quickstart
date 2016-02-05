#!/bin/bash

# Safe shell
set -o nounset
set -o errexit
set -o pipefail

# Test if a file is sourced.
if [ "${BASH_SOURCE[0]}" == "${0}" ]
then 
    echo "The file is not sourced."
else
    echo "The file is sourced."
fi

# http://stackoverflow.com/a/246128
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
