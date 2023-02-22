echo "1. Search"
echo "2. Delete"
echo "3. Exit"
echo "Enter pattern"
read pattern
echo "Enter File name"
read file
echo "Enter choice"
read choice
case $choice in
	1) grep -e "$pattern" $file;;
	2) sed -i "/$pattern/d" $file;;
	3) exit ;;
esac
