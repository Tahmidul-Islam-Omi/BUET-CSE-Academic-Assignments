#include<iostream>
#include<set>
#include<vector>
#include <fstream>
#include <sstream>

using namespace std;

#define pr pair<int, int>

set<pr> convexPoints;

int findSide(pr p1, pr p2, pr p)
{
	int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);

	if (val > 0) {
		return 1;
    }

	if (val < 0) {
		return -1;
    }

	return 0;
}


int lineDist(pr p1, pr p2, pr p)
{
	return abs ((p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first));
}


void quickHull( vector<pr>v1 , int size , pr p1, pr p2, int side)
{
	int index = -1;
	int maxDist = 0;

	for (int i=0; i<size; i++)
	{
		int tempDist = lineDist(p1, p2, v1[i]);

		if ( findSide(p1, p2, v1[i]) == side && tempDist > maxDist)
		{
			index = i;
			maxDist = tempDist;
		}
	}

	if (index == -1)
	{
		convexPoints.insert(p1);
		convexPoints.insert(p2);

		return;
	}

	quickHull(v1, size, v1[index], p1, -findSide(v1[index], p1, p2));
	quickHull(v1, size, v1[index], p2, -findSide(v1[index], p2, p1));
}

void printHull( vector<pr> v1 , int size)
{

	if (size < 3)
	{
		cout << "Only 2 or 1 vertices exist. Not possible to make a fence." << endl;
		return;
	}

	int minxIdx = 0, maxxIdx = 0 ;

	for (int i=1; i<size; i++)
	{
		if (v1[i].first < v1[minxIdx].first) {
			minxIdx = i;
        }

		if (v1[i].first > v1[maxxIdx].first) {
			maxxIdx = i;
        }
	}


	quickHull(v1 , size , v1[minxIdx], v1[maxxIdx], 1);

	quickHull(v1 , size , v1[minxIdx], v1[maxxIdx], -1);


}

int main()
{
    vector<pr> v1;
	
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");

    string line;

    if (!inputFile)
    {
        cout << "Error opening the input file." << endl;
        return 1;
    }

    if(!outputFile) {
        cout << "Error opening the output file." << endl;
        return 1;
    }

    getline(inputFile, line);

    istringstream iss(line);

    int trains;

    iss >> trains;

    while (getline(inputFile , line) )
    {
        istringstream iss(line);

        int xCoord , yCoord;

        iss >> xCoord >> yCoord;

        pr p = make_pair(xCoord , yCoord);
        v1.push_back(p);
    }
    
    
	printHull(v1 , v1.size());

    while (!convexPoints.empty())
	{
		
        outputFile << ( *convexPoints.begin()).first << " " << (*convexPoints.begin()).second << endl;
		convexPoints.erase( convexPoints.begin());
	}

	return 0;
}
