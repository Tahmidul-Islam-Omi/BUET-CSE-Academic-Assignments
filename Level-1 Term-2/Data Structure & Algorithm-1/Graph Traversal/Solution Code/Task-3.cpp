#include <bits/stdc++.h>

using namespace std;

bool visited[100][100];
vector<vector<vector<int>>> dist(100, vector<vector<int>>(100));

bool isInside(int x, int y, int row, int col)
{
    if (x >= 0 && x < row && y >= 0 && y < col)
    {
        return true;
    }

    return false;
}

class cell
{
    int x, y;
    int dis;

public:
    cell()
    {
    }

    cell(int x, int y, int dis)
    {
        this->x = x;
        this->y = y;
        this->dis = dis;
    }

    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }

    int getDis()
    {
        return this->dis;
    }
};

void allpossiblecases(int knightPos[], int row, int col, int ridersMove)
{
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    queue<cell> q;

    q.push(cell(knightPos[0], knightPos[1], 0));
    dist[ knightPos[0] ] [ knightPos[1]].push_back(0);


    cell t;
    int x, y;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            visited[i][j] = false;


    visited[knightPos[0]][knightPos[1]] = true;


    while (!q.empty())
    {
        t = q.front();
        q.pop();


        for (int i = 0; i < 8; i++)
        {
            x = t.getX() + dx[i];
            y = t.getY() + dy[i];

            if (isInside(x, y, row, col) && !visited[x][y])
            {
                visited[x][y] = true;
                int tempdist = t.getDis()+1 ;
                q.push( cell (x, y, t.getDis()+1));
                dist[x][y].push_back(  t.getDis()+1 );
            }
        }
    }
}

int main()

{
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");

    if (!inputFile)
    {
        cout << "Error opening the input file." << endl;
        return 1;
    }

    if (!outputFile)
    {
        cout << "Error opening the output file." << endl;
        return 1;
    }

    int ridersmove[100001];

    string line;
    getline(inputFile, line);

    istringstream iss(line);
    int first, second, third;
    iss >> first >> second >> third;

    int row = first;
    int col = second;
    int riders = third;

    int i=1;

    while (getline(inputFile, line))
    {
        istringstream iss(line);
        iss >> first >> second >> third;

        int startposition[] = {first , second};

        ridersmove[i] = third;
        allpossiblecases( startposition , row, col , third);
        i++;

    }



    vector<int> min;

    int totalsteps = 0;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(dist[i][j].size() == riders) {
                int m=1;
                for(int k=0; k<dist[i][j].size(); k++) {
                    totalsteps += ceil ( (dist[i][j][k]*1.0) / ridersmove[m] );
                    m++;
                }

            min.push_back(totalsteps);
            totalsteps = 0;

            }
        }
    }

    if( min.size() == 0 ) {
        outputFile << -1 << endl;
    }

    else {

    int minSteps = INT_MAX;

    for(int i=0; i<min.size(); i++) {
        if( minSteps > min[i]) {
            minSteps = min[i];
        }
    }

    outputFile << minSteps << endl;

    }


    return 0;
}




