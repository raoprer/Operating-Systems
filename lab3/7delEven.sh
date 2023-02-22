echo Enter file
read file
sed -i '2~2d' $file
