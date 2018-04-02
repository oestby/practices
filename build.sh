#!/bin/bash
for dir in */;
do
    dir=${dir%*/}
    cd ./${dir##*/}/
    ./build.sh
    cd ..
done
