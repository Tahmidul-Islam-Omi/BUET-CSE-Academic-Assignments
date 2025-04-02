#include <bits/stdc++.h>

using namespace std;

class Graph
{

private:
    vector<int> adj[10005];
    vector<int> vis;
    vector<int> path;

    bool dfs(int src, int destination)
    {

        path.push_back(src);

        if (src == destination)
        {
            return true;
        }

        for (auto x : adj[src])
        {
            if (vis[x] == 0)
            {
                vis[x] = 1;
                if (dfs(x, destination) )
                {
                    return true;
                }
            }
        }

        path.pop_back();

        return false;
    }

public:
    Graph() {

    }

    Graph(int n)
    {
        vis.assign(n, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void FindallPaths(int src, int destination , ostream &outstream )
    {

        vis[src] = 1;
        if ( dfs(src, destination) )
        {
            outstream << path.size()-1 << endl;

            for(int i=0; i<path.size() ; i++)
            {
               outstream << path[i] << " ";
            }

            outstream << endl;
        }

        else
        {
            outstream << -1 << endl;
        }

    }


};

int main()

{
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");


    if (!inputFile) {
        cout << "Error opening the input file." << endl;
        return 1;
    }

    if (!outputFile)
    {
        cout << "Error opening the output file." << endl;
        return 1;
    }

    string line;
    int iterate = 1;
    int src, destination, numVertices, numEdges;

    getline(inputFile, line);

    istringstream iss(line);
    int first, second;
    iss >> first >> second;

    numVertices = first;
    numEdges = second;

    Graph graph(numVertices);

    while (getline(inputFile, line)) {

        istringstream iss(line);
        iss >> first >> second;

        if( iterate >= 1 & iterate <= numEdges) {
            graph.addEdge(first, second);
        }

        else {
            src = first;
            destination = second;
        }

        iterate++;
    }

    graph.FindallPaths(src, destination , outputFile);



    return 0;

}
