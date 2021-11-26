filenumbers=($(seq 0 1 9))
distances=($(seq 0.5 0.5 5))
for i in "${filenumbers[@]}"
do
        echo Running process $1 with distance ${distances[$i]}.
        ./getcev2sweep $i ${distances[$i]}
        echo " "
done
