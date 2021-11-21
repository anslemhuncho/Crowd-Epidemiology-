import numpy as np
import csv

## Code adapted from Fofana and Hurford (2017)
width = 100
height = 100
N = 1000
T = 500
steplength = 2

## Simulate separate tracks
directions = np.random.uniform(-np.pi, np.pi, size=N)
tracks = np.zeros((N, T, 2))

for i in range(N):
    ## Create behavioural state sequence
    stateseq = np.ones(T)
    stateseq[50:150] = 0
    stateseq[250:350] = 0

    ## Initial position
    tracks[i][0, :] = np.random.uniform(size=2) * np.array([width, height])

    for t in range(1, T):
        if stateseq[t] == 1:
            turnangle = np.random.vonmises(0, kappa=4)
            theta = directions[i] + turnangle
            x = tracks[i][t - 1, :] + steplength * np.array([np.cos(theta), np.sin(theta)])

            # periodic boundary condition
            if x[0] < 0:
                x[0] = width
            elif x[0] > width:
                x[0] = 0
            if x[1] < 0:
                x[1] = height
            elif x[1] > height:
                x[1] = 0

            tracks[i][t, :] = x
            directions[i] = theta
        else:
            tracks[i][t, :] = tracks[i][t - 1, :]

m=[]
for i in range(len(tracks)):
    m.append(tracks[i][:,0])
    m.append(tracks[i][:,1])

with open('simtracks1000.csv', 'w') as csvfile:
    writer = csv.writer(csvfile)
    for row in m:
        writer.writerow(row)

print('Movement tracks stored to file.')