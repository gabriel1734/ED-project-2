#!/bin/bash
i=0
while [ $i -lt 8 ]
do
    echo "Arquivo $i.txt"
    time ./main.exe entradas/$i.txt
    let i=i+1
done