Q1
cal 8 2017 | tail -n +3 | cut -c 17 | wc -w
Q2
find atmdata -type d | wc -l |||||| find . -type f -print | wc -l 
Q3
find atmdata -type f | wc -l
ls -1 | wc
Q4
 cat mobileSales/2016/01/01/salesData.on.20160101 | tail -n +2 | grep -v "^\w*\b"
 cat mobileSales/2016/01/01/salesData.on.20160101 | tail -n +2 | grep -o "^\w*\b" | sort

 cat mobileSales/2016/01/01/salesData.on.20160101 | tail -n +2 | sort
 


 awk 'NF>1{print $NF}' mobileSales/2016/01/01/salesData.on.20160101 | tail -n +2 | sort -h
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

q8


cp /tmp/someProcess.java backup/
cp /tmp/someProcess.java /home/backup 


q9

grep -o '[1,3,5,7,9][0-9][0-9][-][0-9][0-9][-][0-9][0-9][0-9][0-9]' "^.\{12\}AND" mobileSales/2016/01/01/salesData.on.20160101
+
