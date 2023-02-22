echo "Enter basics and TA"
read basics ta
gs=`bc -l <<<$basics+$ta+0.1*$basics`
echo "Gross Salary is $gs"
