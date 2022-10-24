#!/bin/bash
printf "please enter date and type of sorting: "
read file

Delim=' '
read -ra folder <<< "$file"

date="${folder[0]}"
sortT="${folder[1]}"

output=$(echo "${date}" | sed 's/[/]//g')

if [[ "${sortT}" == "a" ]]; then
  sort -d mobileSales/"${date}"/salesData.on."${output}" | tail -n +2
elif [[ "${sortT}" == "b" ]]; then
  sort -t$'\t' -n -k14 mobileSales/"${date}"/salesData.on."${output}" | tail -n +2
fi

exit 0;
