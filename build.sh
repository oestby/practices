#!/bin/bash
for dir in */;
do
    dir=${dir%*/}
    ./${dir##*/}/build.sh
done
