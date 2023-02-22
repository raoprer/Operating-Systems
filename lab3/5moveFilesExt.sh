echo Enter the extension
read ext
echo Enter the directory
read dir
result=`find ./ -maxdepth 1 -name *$ext`
mkdir $dir
for i in $result
do
    mv $i $dir
done
