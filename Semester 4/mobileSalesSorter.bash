#!/bin/bash
printf "please enter date and type of sorting: "
read file

Delim=' '
read -ra folder <<< "$file"

date="${folder[0]}"
sortT="${folder[1]}"


output=cat ${date} | sed 's/[/]//g'


awk 'NF>1{print $NF}' mobileSales/"${date}"/salesData.on."${output}" | tail -n +2 | sort -h
