#!/bin/bash

# read a path and find out the last element on it:

printf "enter a date: "
read Date
#declaring variables
$year
$mounth
$day

#making DATE into a array
Delim=' '
read -ra DATE <<< "$Date"

#variables that take from array
year="${DATE[0]}"
mounth="${DATE[1]}"
day="${DATE[2]}"

#example of for loop
#for i in "${ADDR[@]}"; do
#	echo "$i"

printf "you entered the date [%s][%s][%s]\n" "${year}" "${mounth}" "${day}"
days=('mon' 'tue' 'wed' 'thu' 'fri' 'sat' 'sun')
mounths=('January' 'February' 'March' 'April' 'May' 'June' 'July' 'August' 'September' 'October' 'November' 'December')
$cuta
#example of for and if
#for i in "${days[@]}"; do

#	if [[ "${i}" == "$day" ]]; then
#        printf "Strings are equal.\n"
#    else
#        printf "not found\n"
#    fi
#done
# end of exapmle and if
$dayOfWeek
if [[ "${days[0]}" == "$day" ]]; then
        cuta="5"
        dayOfWeek="Monday"
elif [[ "${days[1]}" == "$day" ]]; then
        cuta="8"
        dayOfWeek="Tuesday"
elif [[ "${days[2]}" == "$day" ]]; then
        cuta="11"
        dayOfWeek="Wednesday"
elif [[ "${days[3]}" == "$day" ]]; then
        cuta="14"
        dayOfWeek="Thursday"
elif [[ "${days[4]}" == "$day" ]]; then
        cuta="17"
        dayOfWeek="Friday"
elif [[ "${days[5]}" == "$day" ]]; then
        cuta="20"
        dayOfWeek="Saturday"
elif [[ "${days[6]}" == "$day" ]]; then
        cuta="2"
        dayOfWeek="Sunday"
else
    printf "Error: invalid input\n\nUsage: weekDaysNumber.bash <year> <month> <day>\n\nwhere\n\n1 <= year <= 9999\n\n1 <= month <= 12\n\nday is one of the following - sun, mon, tue, wed, thu, fri, sat\n"
    exit 1
fi


printf "%s %s has " "${mounths[${mounth}-1]}" "${year}"
cal ${mounth} ${year} | tail -n +3 | cut -c ${cuta} | wc -w #| printf "%s\n""${dayOfWeek}"
printf "%s\n" "${dayOfWeek}"


exit 0
