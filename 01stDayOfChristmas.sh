#!/bin/bash
frequency=0
#rm thelist
#found=''
#while [ $found -z ]
#anotherlist=''
#do

while IFS='' read -r line || [[ -n "$line" ]]; do
    echo "Text read from file: $line"
    typeset -i variable=$line 
    frequency=$(( frequency+variable ))
   # anotherlist=$(( ` echo "$anotherlist" "$frequency" ` )) 
   # listoffrequencies=` echo $frequency `
   # echo "$listoffrequencies" >> thelist
   # cat thelist
   # sleep 2 
   # key='\'$frequency 
   # echo $key  
   # found=` grep ['$key'] thelist ` 
   # echo it is: $found

done < "$1"
#echo $anotherlist
#done
echo Resulting frequency is $frequency

#cat listoffrequencies
#cut -c1 $1 >> signs
#cat signs
#sleep 1


exit 


