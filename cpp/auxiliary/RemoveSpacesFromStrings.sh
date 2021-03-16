#!/bin/bash
echo "Removes all spaces from the input strings"
sed 's/ //g' $1 >> $1"prep" 
exit

