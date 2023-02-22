echo Enter the text file name
read file
if [ -f "/home/student/210911002/lab3/$file" ] ; then
     echo $file is a regular file
elif [ -d "/home/student/210911002/lab3/$file" ] ; then
     echo $file is a directory
else
     echo Neither a text file nor a directory
fi
