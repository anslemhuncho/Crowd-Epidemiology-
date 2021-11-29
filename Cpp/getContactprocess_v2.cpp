#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>
#include <numeric>

using namespace std;

void getContacts(float tracks[][500], int rwstatuts[][1000], int rwexposed[500]);
float distance(float a[2], float b[2]);
 
int main(int argc, char* argv[])
{
	string s = argv[1];
	stringstream geek(s);
	int nr; 
    	geek >> nr;
	
	float (*tracks)[500] = new float[2000][500];
	int (*rwstatuts)[1000] = new int[501][1000];
	int *rwexposed = new int[500];
	
	// Set all individuals to susceptible at time zero
	for (int i = 0; i < 999; i++) {
		rwstatuts[0][i] = 0;
	}
	
	ifstream file("simtracks1000.csv");
	
	for (int i = 0; i < 2000; i++)
	{
	
		string line;
		getline(file, line);
		stringstream iss(line);
		for (int j = 0; j <500; j++)
		{
			string val;
			getline(iss, val, ',');
		
			stringstream convertor(val);
			convertor >> tracks[i][j];
		}
	}
	
	cout << "Processing contacts ..." << endl;
	
	getContacts(tracks,rwstatuts,rwexposed);
	
	////////////////////////////////////////////////////////////////////
	ofstream output;
	char filename[80];
	sprintf(filename, "rwexposed%d.txt", nr);
	output.open(filename);
	for (int i = 0; i < 500; i ++) {
		output << rwexposed[i] << '\n';
	}
	output.close();
	////////////////////////////////////////////////////////////////////
	cout << "Results stored in files." << endl;
	
	return 0;
}

void getContacts(float tracks[][500], int rwstatuts[][1000], int rwexposed[500])
{
	float a[2];
	float b[2];
	int state;
	
	for (int k = 0; k < 500; k++)
	{
		for (int i = 0; i < 2000; i+=2)
		{
			for (int j = 0; j < 2000; j+=2)
			{
				if (j != i)
				{
					a[0] = tracks[i][k];
					a[1] = tracks[i+1][k];
					b[0] = tracks[j][k];
					b[1] = tracks[j+1][k];
						
					state = rwstatuts[k][i/2];
					if ((j == 1998) && (distance(a,b) < 1)) {
						rwstatuts[k+1][i/2] = 1;
							
					} else if (state == 1) {
						rwstatuts[k+1][i/2] = 1;
					}	
				}	
			}	
		}
		
		// Get the number of infectious individuals
		int inf = accumulate(rwstatuts[k], rwstatuts[k] + 1000, 0);
		rwexposed[k] = inf;
	}
}

float distance(float a[2], float b[2])
{
	return sqrt(pow(b[0] - a[0],2) + pow(b[1] - a[1],2));
}

