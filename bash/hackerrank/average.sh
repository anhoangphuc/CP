read number
i=1
sum=0
while [[ $i -le $number ]]
do
	read x
	sum=$(( sum + x ))
	(( i = i + 1 ))
done
res=$(bc -l <<< "$sum / $number")
printf "%.3f" $res
