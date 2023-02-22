functionSort(){
declare -a arr
x=0
for num in $@; do
    arr[((x++))]=$num
done

n=$#

for((i=0;i<n-1;i++)); do
    for((j=0;j<n-1-i;j++)); do
        if [[ ${arr[$j]} > ${arr[$j+1]} ]];then
            temp=${arr[$j]}
            arr[$j]=${arr[$j+1]}
            arr[$j+1]=$temp
        fi
    done
done
echo "The sorted array is:"
x=1
for i in ${arr[@]};do
    echo  "$i"
    ((x++))
done
}
functionSort "hello" "apple"
