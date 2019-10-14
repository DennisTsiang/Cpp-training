#!/bin/bash

for i in {2..15}
do
    ./build-one.sh "$i"
done

./reset-project.sh
