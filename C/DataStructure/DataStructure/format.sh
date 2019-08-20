#!/bin/bash
# Author: estKey

echo "Processing..."
for i in *.cpp *.hpp
 do
   dist_folder=${i%.*}
   # echo $dist_folder
   # skip the main.cpp and stdafx.hpp for creating folders
   if [ "$dist_folder" = "main" -o "$dist_folder" = "stdafx" ]
   then
        echo "skip $dist_folder"
        continue
   fi
   if [ ! -d $dist_folder ]
   then
   mkdir ${dist_folder}
   echo "the folder with the name of $dist_folder has been created."
   fi
   mv $i ./${dist_folder}/$i
   echo "$i has been moved to the same name folder of $dist_folder"
done
echo "Done."
read -n 1 -p "Press any key to terminate"