####################### PUSH_SWAP TESTER BY CONOEL #############################

### PRELUDE ###

clear
read -p "Number of tests : " NB_TEST
clear
read -p "Check results ? [y/n] : " TEST_RESULTS
clear
read -p "Size of the array : " SIZE

MAX=0
MIN=-1
TOTAL=0
I=0
TOT_KO=0

### CALCUL ###

while [ $I -lt $NB_TEST ]
do
	ARG=`ruby -e "puts (1..($SIZE)).to_a.shuffle.join(' ')"`

	if [ "$TEST_RESULTS" == "y" ]
	then
		RETURN=`./push_swap $ARG | ./checker $ARG`
		if [ "$RETURN" == "KO" ]
		then
			echo "\033[31mKO BITCH !\033[0m"
			TOT_KO=`echo "($TOT_KO) + 1" | bc`
		fi
	fi

	RESULT=`./push_swap $ARG | wc -l | bc`
	TOTAL=`echo "($RESULT) + ($TOTAL)" | bc`

	if [ $RESULT -le $MIN ] || [ $MIN -le 0 ]
	then
		MIN=$RESULT
	fi
	if [ $MAX -le $RESULT ]
	then
		MAX=$RESULT
	fi
	I=`echo "($I) + 1" | bc`
	clear
	echo "[\033[32m$I\033[0m/$NB_TEST]"
done
MOYENNE=`echo "($TOTAL) / ($NB_TEST)" | bc -l`
DIR="result_histo"

touch $DIR

clear
echo "Array Size : $SIZE"
echo "Nb tests   : $NB_TEST"
echo "//===========================\\\\\\"
if [ "$TEST_RESULTS" == "y" ]
then
		printf "||         KO  : \033[31m%-7d\033[0m     ||\n" $TOT_KO
fi
printf "||         Max : \033[31m%-7d\033[0m     ||\n" $MAX
printf "||         Moy : \033[33m%.1f\033[0m\n" $MOYENNE
printf "||         Min : \033[32m%-7d\033[0m     ||\n" $MIN
echo "\\\\============================//\n\n"
read -p "Commentary : " COMM
echo "Result wrote in ./$DIR"

echo "Array Size : $SIZE" >> "$DIR"
echo "Nb tests   : $NB_TEST" >> "$DIR"
echo "//===========================\\\\\\"  >> "$DIR"
if [ "$TEST_RESULTS" == "y" ]
then
		printf "||         KO  : \033[31m%-7d\033[0m     ||\n" $TOT_KO  >> "$DIR"
fi
printf "||         Max : \033[31m%-7d\033[0m     ||\n" $MAX  >> "$DIR"
printf "||        *Moy : \033[33m%.1f\033[0m\n" $MOYENNE  >> "$DIR"
printf "||         Min : \033[32m%-7d\033[0m     ||\n" $MIN  >> "$DIR"
echo "\\\\============================//\n" >> "$DIR"
echo $COMM >> "$DIR"