# Crowd-Epidemiology

Software for "Analysing the dynamic relationship between crowd behaviour and spread of infection at large scale events using Wi-Fi mobility data"

Philip Rutten, Michael H. Lees, Sander Klous, Hans Heesterbeek, Peter M.A. Sloot

Code created on: Apple macOS Big Sur Version 11.6<br/>
Python version 3.8.8<br/>
Jupyter Notebook 6.3.0<br/>
Packages: pandas, numpy, powerlaw, matplotlib<br/>
g++ version 4.2.1 Apple clang version 12.0.5 (clang-1205.0.22.9)

## Random walk simulations

Code organised in 3 sets of simulations, executed by the three Bash files:<br/>
runsims1.sh: weight distributions on 3 different random walk models (Figure 6 in manuscript)<br/>
runsims2.sh: SE-model comparison on 4 different random walk models (Figure 7b in manuscript)<br/>
runsims3.sh: SE-model comparison on 4 different random walk models (Figure 7a in manuscript)<br/>

The Python files generate the random walks.<br/>
The C++ files run the contact and infection transmission process on top of the generated random walks.<br/>

The results (stored output from the C++ files) are analysed/visualised in the Jupyter notebook:<br/>
RW-simulation-output.ipynb

To compile the C++ programs, run the commands:<br/>
g++ -o getw getWeights.cpp<br/>
g++ -o getcp2 getContactprocess_v2.cpp<br/>
g++ -o getcp3 getContactprocess_v3.cpp<br/>

To give permission to Bash files, run:<br/>
chmod 755 runsims1.sh
