filenumbers=($(seq 0 1 9))
for i in "${filenumbers[@]}"
do
        echo Running the RW process.
        python RWprocess.py
        echo Getting the weights.
        ./getw $i
        echo " "
done

filenumbers=($(seq 10 1 39))
for i in "${filenumbers[@]}"
do
        echo Running the RW process.
        python CTRWprocess.py
        echo Getting the weights.
        ./getw $i
        echo " "
done

filenumbers=($(seq 40 1 69))
for i in "${filenumbers[@]}"
do
        echo Running the RW process.
        python regCTRWprocess.py
        echo Getting the weights.
        ./getw $i
        echo " "
done

echo "Done!"
