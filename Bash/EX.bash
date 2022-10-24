#!/bin/bash


cal 8 2017 | tail -n +3 | cut -c 17 | wc -w

find Desktop -type d | wc 

ls -1 | wc

 cat mobileSales/2016/01/01/salesData.on.20160101 | tail -n +2 | grep -o "^\w*\b"

 awk 'NF>1{print $NF}' mobileSales/2016/01/01/salesData.on.20160101 | tail -n +2
 awk scans the numbers of lines
 awk is like a scanner

 nf gose for a number of records



 q6

cd - go HOME or change directory
touch - to create a file
chmod - to change permissions of a file
witch - to locate a file or command
echo - returns a number (error) to terminal if used as "echo $?" returns the status of the last command
cat - prints a file stff on terminal
ls - look a s directory in list for ls -la to veiw all files in the directory
mkdir - create a directory
rmdir - deletes a directory
pwd - present working directory

q7

it will eaither error out or not print out any promted
