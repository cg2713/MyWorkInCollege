#!/bin/bash

printf "please enter a file path: "
read fileP
printf "the file entered was %s\n" "${fileP}"
	if [[ ! -d $fileP ]]; then
	    printf "%s does not exist or is not accessible" "${filepath}"
	else
        printf "%s has " "${fileP}" 
        ls ${fileP} -1 | grep -v ^1 |  wc -l 
        printf "files"
         
	fi

printf "\n"

exit 0
