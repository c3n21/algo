#/bin/bash
gcc "$1" -g -o main && ./main "${@:2}"
