
#!/bin/bash

# 同名文件与文件夹的意思是，文件名中的下划线_前面的部分相同
# 批量自动把同名文件分别放入同名文件夹中

# 处理的文件是后缀名为.jpg的文件
for i in *.cpp *.hpp;do
    destination_folder=${i%.*}
   echo $destination_folder
    if [ destination_folder -eq "main" -o destination_folder -eq "stdafx"] then continue
    if [ ! -d $destination_folder ];then
        mkdir ${destination_folder}
        echo "the folder with the name of $destination_folder has been created."
    fi
    mv $i ./${destination_folder}/$i
    echo "$i has been moved to the same name folder of $destination_folder"
done