# Crowd-Epidemiology

Software for "Analysing the dynamic relationship between crowd behaviour and spread of infection at large scale events using Wi-Fi mobility data"

Philip Rutten, Michael H. Lees, Sander Klous, Hans Heesterbeek, Peter M.A. Sloot

Code created on: Apple macOS Big Sur Version 11.6<br/>
Python version 3.8.8<br/>
Jupyter Notebook 6.3.0<br/>
Packages: pandas, numpy, powerlaw, networkx, matplotlib<br/>
g++ version 4.2.1 Apple clang version 12.0.5 (clang-1205.0.22.9)<br/>

## Random walk simulations

Code organised in 3 sets of simulations, executed by the three Bash files:<br/>
runsims1.sh: weight distributions on 3 different random walk models (Figure 6 in manuscript)<br/>
runsims2.sh: SE-model comparison on 4 different random walk models (Figure 7b in manuscript)<br/>
runsims3.sh: SE-model comparison on 4 different random walk models (Figure 7a in manuscript)<br/>

The Python files generate the random walks (note: each iteration overwrites the same .csv file).<br/>
The C++ files run the contact and infection transmission process on the newly generated .csv file containing the random walks.<br/>
In the Jupyter notebook all the results (stored output from the C++ files) are analysed and plotted:<br/>
RW-simulation-output.ipynb

To compile the C++ programs, run the commands:<br/>
g++ -o getw getWeights.cpp<br/>
g++ -o getcp2 getContactprocess_v2.cpp<br/>
g++ -o getcp3 getContactprocess_v3.cpp<br/>

To give permission to Bash files, for each file run:<br/>
chmod 755 runsims1.sh

All simulation times are less than one hour on a standard laptop.

## Movement track analysis

In the Jupyter notebook movement-trajectories-visualisations.ipynb the example tracks are plotted, and the waiting times are measured (Figure 1 in manuscript).<br/>
The model selection for the waiting times (Figure 2) is done in the Jupyter notebook MLE-fits-model-selection.ipynb.<br/>

## Aggregated contact networks

In the C++ files getcontactEvents_v2.cpp and getcontactEvents_v2a.cpp the contact sequences are generated.<br/>
The programs take as input the movement tracks stored in CSV files realtracks362ajax.csv and realtracks1048.csv.<br/>
The C++ files can be compiled as follows:<br/>
g++ -o getcev2 getcontactEvents_v2.cpp<br/>
g++ -o getcev2a getcontactEvents_v2a.cpp

After running the executable, i.e. the command:<br/>
./getcev2<br/>
the program stores the file “contactsequence1048.csv” in the same directory.<br/>

The parameter sweeps over the distance threshold parameter are implemented in the Bash files:<br/>
runsweep1.sh: iteratively runs C++ file getcontactEvents_v2_sweep.cpp on specified input parameter values.<br/>
runsweep2.sh iteratively runs C++ file getcontactEvents_v2a_sweep.cpp on specified input parameter values.

Make sure to compile the C++ programs with proper executable file names:<br/>
g++ -o getcev2sweep getcontactEvents_v2_sweep.cpp<br/>
g++ -o getcev2asweep getcontactEvents_v2a_sweep.cpp

To give permission to the Bash files, run the commands:<br/>
chmod 755 runsweep1.sh<br/>
chmod 755 runsweep2.sh

In the Jupyter notebook aggregated-network-analysis.ipynb the degree distributions are extracted from the contact sequences (stored in the C++ output files) (Figure 4 in manuscript).<br/>
The contact duration and weight distributions (Figure 5 in manuscript) are extracted from the same contact sequences.

## Transmission over the network

In the Jupyter notebook network-transmission-analysis.ipynb all the contact rates and incidence curves are analysed (Figures 8, 9, 10, 11 in manuscript) from the generated contact sequences.<br/>

Some of the analyses may take up to an hour on a standard laptop.
