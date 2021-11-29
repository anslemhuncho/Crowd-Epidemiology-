filenumbers=($(seq 0 1 9))
distances=($(seq 0.5 0.5 5))
for i in "${filenumbers[@]}"
do
        echo Running process $1 with distance ${distances[$i]}.
        Cpp/getcev2sweep $i ${distances[$i]}
        echo " "
done
