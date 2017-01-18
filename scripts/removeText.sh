#!/bin/bash

# function removes a specified string (argument $2) with a new string (argument $3) in a given file (argument $2)

ReplaceStringInFile(){
 fileName=$1
 filenameNoFormat=${fileName%.*}
 pdftk $fileName output $filenameNoFormat"-compressed.pdf" uncompress
 #modify
 sed 's/'$2'/'$3'/g' < $filenameNoFormat"-compressed.pdf" > $filenameNoFormat"-new.pdf"
 #compress
 pdftk $filenameNoFormat"-new.pdf" output $fileName compress
 rm $filenameNoFormat"-compressed.pdf" $filenameNoFormat"-new.pdf"
}

stringToReplace=$2
ToReplace=$(echo $stringToReplace| tr " " "\n")
cd $1
for iFile in *.pdf
do 
  echo $iFile
  for iToReplace in $ToReplace
  do
    ReplaceStringInFile $iFile $iToReplace $3
  done
done

