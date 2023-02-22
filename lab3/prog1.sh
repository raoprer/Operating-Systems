echo $0 $1 $2
read a b
echo -e "a is $a \nb is $b"
c=`expr $a+$b`
echo "c is $c"
