#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

void getContacts(float tracks[][500], int contactmatrix[][1000]);
float distance(float a[2], float b[2]);
 
int main(int argc, char* argv[])
{
	string s = argv[1];
	stringstream geek(s);
	int nr; 
    	geek >> nr;
	
	float (*tracks)[500] = new float[2000][500];
	int (*contactmatrix)[1000] = new int[1000][1000];
	vector<vector<float> > weights;
	
	ifstream file("simtracks1000.csv");
	
	for (int i = 0; i < 2000; i++)
	{
	
		string line;
		getline(file, line);
		stringstream iss(line);
		for (int j = 0; j < 500; j++)
		{
			string val;
			getline(iss, val, ',');
		
			stringstream convertor(val);
			convertor >> tracks[i][j];
		}
	}
	
	cout << "Building contact matrix ..." << endl;
	
	getContacts(tracks,contactmatrix);
	
	cout << "Contact matrix has been built." << endl;
	
	for (int i = 0; i < 1000 - 1; i++)	
	{
		for (int j = i + 1; j < 1000; j++)
		{
			if (contactmatrix[i][j] > 0)
			{
				vector<float> foo;
				foo.push_back(i);
				foo.push_back(j);
				foo.push_back(contactmatrix[i][j]);
				weights.push_back(foo);
			}
		}
	}
	
	////////////////////////////////////////////////////////////////////
	ofstream output;
	char filename[80];
	sprintf(filename, "weights1000sim%d.csv", nr);
	output.open(filename);
	for (int i = 0; i < weights.size(); i ++) {
		output << weights[i][0] << "," << weights[i][1] << "," << weights[i][2] << '\n';
	}
	output.close();
	////////////////////////////////////////////////////////////////////
	cout << "Weights stored in file." << endl;
	
	return 0;
}

void getContacts(float tracks[][500], int contactmatrix[][1000])
{
	float a[2];
	float b[2];
	for (int k = 0; k < 500; k++)
	{
		for (int i = 0; i < 2000 - 2; i+=2)
		{
			if (tracks[i][k] != 0 && tracks[i+1][k] != 0) {
				for (int j = i + 2; j < 2000; j+=2)
				{
					if (j != i)
					{
						if (tracks[j][k] != 0 && tracks[j+1][k] != 0) {
							a[0] = tracks[i][k];
							a[1] = tracks[i+1][k];
							b[0] = tracks[j][k];
							b[1] = tracks[j+1][k];
							
							if (distance(a,b) < 1)
							{								
								contactmatrix[i/2][j/2] += 1;
								contactmatrix[j/2][i/2] += 1;
							} 
						}
					}	
				}
			}
		}
	}
}

float distance(float a[2], float b[2])
{
	return sqrt(pow(b[0] - a[0],2) + pow(b[1] - a[1],2));
}

