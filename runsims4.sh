filenumbers1=($(seq 0 1 19))
filenumbers2=($(seq 0 1 29))
means=($(seq 0.01 0.02 0.4))
for i in "${filenumbers1[@]}"
do
	for j in "${filenumbers2[@]}"
	do
        	echo Running the CRW process.
        	python Python/CRWprocess.py
		k=$(($i*30 + $j))
		echo Running process $k with mu is ${means[$i]}.
        	Cpp/getcp3sweep $k ${means[$i]}
        	echo " "
	done
done

for i in "${filenumbers1[@]}"
do
	for j in "${filenumbers2[@]}"
        do
        	echo Running the CTCRW process.
        	python Python/CTCRWprocess.py
		k=$(($i*30 + $j + 600))
        	echo Running process $k with mu is ${means[$i]}.
        	Cpp/getcp3sweep $k ${means[$i]}
		echo " "
	done
done
