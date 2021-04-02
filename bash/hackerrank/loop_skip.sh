for i in {1..100}
do
	if [[ $(( $i % 2 )) -eq 0 ]] 
	then 
		continue
	fi
	echo $i
done	
