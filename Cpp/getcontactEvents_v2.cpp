#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

void getContactEvents(float tracks[][3479], vector<vector<float> > &contacts);
float distance(float a[2], float b[2]);
 
int main()
{
	float (*tracks)[3479] = new float[2096][3479];
	vector<vector<float> > contacts;
	
	ifstream file("realtracks1048.csv");
	
	for (int i = 0; i < 2096; i++)
	{
	
		string line;
		getline(file, line);
		stringstream iss(line);
		for (int j = 0; j < 3479; j++)
		{
			string val;
			getline(iss, val, ',');
		
			stringstream convertor(val);
			convertor >> tracks[i][j];
		}
	}
	
	cout << "Building contacts sequence ..." << endl;
	
	getContactEvents(tracks,contacts);
	
	cout << "Contacts sequence has been built." << endl;
	
	////////////////////////////////////////////////////////////////////
	ofstream output;
	output.open("contactsequence1048.csv");
	for (int i = 0; i < contacts.size(); i ++) {
		output << contacts[i][0] << "," << contacts[i][1] << "," << contacts[i][2] << '\n';
	}
	output.close();
	////////////////////////////////////////////////////////////////////
	cout << "Contacts stored in file." << endl;
	
	return 0;
}

void getContactEvents(float tracks[][3479], vector<vector<float> > &contacts)
{
	float a[2];
	float b[2];
	for (int t = 0; t < 3479; t++)
	{
		for (int i = 0; i < 2096 - 2; i+=2)
		{
			if (tracks[i][t] != 0 && tracks[i+1][t] != 0) {
				for (int j = i + 2; j < 2096; j+=2)
				{
					if (j != i)
					{
						if (tracks[j][t] != 0 && tracks[j+1][t] != 0) {
							a[0] = tracks[i][t];
							a[1] = tracks[i+1][t];
							b[0] = tracks[j][t];
							b[1] = tracks[j+1][t];
							
							if (distance(a,b) < 1.5)
							{				
								vector<float> foo;
								foo.push_back(i/2);
								foo.push_back(j/2);
								foo.push_back(t);
								contacts.push_back(foo);
								
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


