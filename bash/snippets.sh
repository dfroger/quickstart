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
HERE="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# https://www.cyberciti.biz/faq/bash-infinite-loop/
while true
do
    echo "Press [CTRL+C] to stop.."
    sleep 1
done

# Get timestamp
timestamp=$(date +%s)
