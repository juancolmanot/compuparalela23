#!/bin/bash


if [ -f "$1" ]; then
    while read line
    do
        filename="with-flags$(echo $line | tr -d " ")"
        ./deploy_ns.sh -f "$line" -o "$filename"
    done < $1

else
    filename="with-flags$(echo "$1" | tr -d " ")"
    ./deploy_ns.sh -f "$1" -o "$filename"
fi

