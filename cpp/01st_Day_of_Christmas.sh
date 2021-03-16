#!/bin/bash
frequency=0
rm thelist
rm sortfile
rm freqfile
found=0
#nf=0

while [ $found -eq 0 ]
do
#sleep 1
while IFS='' read -r line || [[ -n "$line" ]]; do
#    echo "Text read from file: $line"
    typeset -i change=$line 
    frequency=$(( frequency+change ))
    anotherlist=` echo $anotherlist" "$frequency ` 
    echo $frequency >> freqfile 
    #cat freqfile 
    sort freqfile | uniq > sortfile
    #cat sortfile
    fn=` cat freqfile | wc -l `
    fs=` cat sortfile | wc -l `
    #echo $fn $fs 
    if [ $fs != $fn ]
    then
    found=$(( 1 ))
    solution=$frequency
    echo RJESENJE JE $solution
    break
    fi
done < "$1"
echo Resulting frequency is $frequency
done
exit 


