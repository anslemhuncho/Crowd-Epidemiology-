filenumbers=($(seq 0 1 9))
for i in "${filenumbers[@]}"
do
        echo Running the RW process.
        python Python/RWprocess.py
        echo Getting the weights.
        Cpp/getw $i
        echo " "
done

filenumbers=($(seq 10 1 39))
for i in "${filenumbers[@]}"
do
        echo Running the RW process.
        python Python/CTRWprocess.py
        echo Getting the weights.
        Cpp/getw $i
        echo " "
done

filenumbers=($(seq 40 1 69))
for i in "${filenumbers[@]}"
do
        echo Running the RW process.
        python Python/regCTRWprocess.py
        echo Getting the weights.
        Cpp/getw $i
        echo " "
done

echo "Done!"
