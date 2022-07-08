filenumbers=($(seq 0 1 9))
distances=($(seq 1 1 10))
for i in "${filenumbers[@]}"
do
        echo Running process $i with distance ${distances[$i]}.
        Cpp/getcev2sweep $i ${distances[$i]}
        echo " "
done
