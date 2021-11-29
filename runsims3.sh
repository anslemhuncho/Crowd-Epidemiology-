# Run SE-model simulations
filenumbers=($(seq 120 1 149))
for i in "${filenumbers[@]}"
do
        echo Running the CRW process.
        python Python/CRWprocess.py
        echo Running the contact and infection process.
        Cpp/getcp2 $i
        echo " "
done

echo "Now starting next set of simulations.\n"

filenumbers=($(seq 150 1 179))
for i in "${filenumbers[@]}"
do
        echo Running the regCTCRW process.
        python Python/regCTCRWprocess.py
        echo Running the contact and infection process.
        Cpp/getcp2 $i
        echo " "
done

echo "Now starting next set of simulations.\n"

filenumbers=($(seq 180 1 209))
for i in "${filenumbers[@]}"
do
        echo Running the CRW process.
        python Python/CRWprocess.py
        echo Running the contact and infection process.
        Cpp/getcp3 $i
        echo " "
done

echo "Now starting next set of simulations.\n"

filenumbers=($(seq 210 1 239))
for i in "${filenumbers[@]}"
do
        echo Running the regCTCRW process.
        python Python/regCTCRWprocess.py
        echo Running the contact and infection process.
        Cpp/getcp3 $i
        echo " "
done

echo "Done!"
