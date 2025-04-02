#include<iostream>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

class FindMinPlatforms {
    vector<int>v;

    public:

    FindMinPlatforms( ) {
        v.resize(100000);
    }

    FindMinPlatforms(vector<int> v) {
        this->v = v;
    }

    int PlatformsNeeded() {

        int cnt = 0;

        int ans = 0;

        for(int i = 1; i < v.size(); i++) {
            
            cnt+= v[i];

            ans = max(ans, cnt);
        }

        return ans;
    }


};

int main()

{
    ifstream inputFile("input_2.txt");
    string line;

    if (!inputFile)
    {
        cout << "Error opening the input file." << endl;
        return 1;
    }

    getline(inputFile, line);

    istringstream iss(line);

    int trains;

    iss >> trains;

    int arrTime , depTime;

    vector<int> v(100000 , 0);

     while (getline(inputFile, line)) {
        istringstream iss(line);

        iss >> arrTime >> depTime;
        v[arrTime]++;
        v[depTime+1]--;

     }

     FindMinPlatforms obj(v);

     cout << obj.PlatformsNeeded() << endl;


}