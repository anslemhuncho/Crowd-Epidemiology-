# Run SE model simulations
filenumbers=($(seq 0 1 29))
for i in "${filenumbers[@]}"
do
        echo Running the CRW process.
        python CRWprocess.py
        echo Running the contact and infection process.
        ./getcp2 $i
        echo " "
done

echo "Now starting next set of simulations.\n"

filenumbers=($(seq 30 1 59))
for i in "${filenumbers[@]}"
do
        echo Running the CTCRW process.
        python CTCRWprocess.py
        echo Running the contact and infection process.
        ./getcp2 $i
        echo " "
done

echo "Now starting next set of simulations.\n"

filenumbers=($(seq 60 1 89))
for i in "${filenumbers[@]}"
do
        echo Running the CRW process.
        python CRWprocess.py
        echo Running the contact and infection process.
        ./getcp3 $i
        echo " "
done

echo "Now starting next set of simulations.\n"

filenumbers=($(seq 90 1 119))
for i in "${filenumbers[@]}"
do
        echo Running the CTCRW process.
        python CTCRWprocess.py
        echo Running the contact and infection process.
        ./getcp3 $i
        echo " "
done

echo "Done!"
