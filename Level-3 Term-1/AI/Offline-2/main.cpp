#include <bits/stdc++.h>
using namespace std;

pair<int, int> find_max_edge(vector<vector<int>> &edges, int vertices)
{

    pair<int, int> max_edge;

    int curr_weight = 0;

    // Find maximum weight edge
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            if (edges[i][j] > curr_weight)
            {
                curr_weight = edges[i][j];
                max_edge.first = i;
                max_edge.second = j;
            }
        }
    }

    return max_edge;
}

int calculate_cut_weight(pair<vector<int>, vector<int>> max_cut_Graph, vector<vector<int>> &edges)
{
    vector<int> &S = max_cut_Graph.first;
    vector<int> &S_bar = max_cut_Graph.second;
    
    int cut_weight = 0;

    unordered_set<int> S_set(S.begin(), S.end());
    
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S_bar.size(); j++) {
            cut_weight += edges[S[i]][S_bar[j]];
        }
    }
    
    return cut_weight;
}

int randomized_MaxCut(int vertices, vector<vector<int>> edges) {
    int total_cut_weight = 0;

    int trials = 1000;

    for (int i = 0; i < trials; i++) {
        // Randomly partition the vertices into two sets
        vector<int> S;
        vector<int> S_bar;

        for (int j = 1; j <= vertices; j++) {
            if (rand() % 2 == 0) {
                S.push_back(j);
            } else {
                S_bar.push_back(j);
            }
        }

        int cut_weight = calculate_cut_weight({S, S_bar}, edges);
        total_cut_weight += cut_weight;
    }

    return total_cut_weight / trials;
}

int LocalSearch(pair<vector<int>, vector<int>> max_cut_Graph, vector<vector<int>> &edges, int cut_weight)
{

    vector<int> S = max_cut_Graph.first;
    vector<int> S_bar = max_cut_Graph.second;

    int max_cut_weight = cut_weight;

    // Try moving vertices from S to S_bar
    for (int i = 0; i < S.size(); i++)
    {
        int current_vertex = S[i];

        S.erase(S.begin() + i);
        S_bar.push_back(current_vertex);

        int new_cut_weight = calculate_cut_weight({S, S_bar}, edges);

        if (new_cut_weight > max_cut_weight)
        {
            max_cut_weight = new_cut_weight;
            i--;
        }

        else {
            S.insert(S.begin() + i, current_vertex); // Insert back at original position
            S_bar.pop_back();
        }
    }

    // Try moving vertices from S_bar to S
    for (int i = 0; i < S_bar.size(); i++)
    {
        int current_vertex = S_bar[i];

        S_bar.erase(S_bar.begin() + i);
        S.push_back(current_vertex);

        int new_cut_weight = calculate_cut_weight({S, S_bar}, edges);

        if (new_cut_weight > max_cut_weight)
        {
            max_cut_weight = new_cut_weight;
            i--;
        }

        else {
            S_bar.insert(S_bar.begin() + i, current_vertex); // Insert back at original position
            S.pop_back();
        }
    }

    return max_cut_weight;
}

pair<vector<int>, vector<int>> SemiGreedyMaxCut(int vertices, vector<vector<int>> &edges, int alpha = 0.5)
{

    pair<vector<int>, vector<int>> max_cut_Graph;

    vector<int> S;
    vector<int> S_bar;

    pair<int, int> max_edge = find_max_edge(edges, vertices);

    S.push_back(max_edge.first);
    S_bar.push_back(max_edge.second);

    vector<int> unassigned_vertices;

    for (int i = 1; i <= vertices; i++) {
        if (i != max_edge.first && i != max_edge.second) {
            unassigned_vertices.push_back(i);
        }
    }

    while(!unassigned_vertices.empty()) {

        vector< pair<int, int>> gains; // vertex index, max gain

        for(int v=0; v < unassigned_vertices.size(); v++) {
            int sigma_S = 0;
            int sigma_S_bar = 0;

            for(int j = 0; j < S_bar.size(); j++) {
                sigma_S += edges[unassigned_vertices[v]][S_bar[j]];
            }

            for(int j = 0; j < S.size(); j++) {
                sigma_S_bar += edges[unassigned_vertices[v]][S[j]];
            }

            gains.push_back({v, max(sigma_S, sigma_S_bar)});
        }

        int minGain = INT_MAX;
        int maxGain = INT_MIN;
        
        for(int i = 0; i < gains.size(); i++) {
            minGain = min(minGain, gains[i].second);
            maxGain = max(maxGain, gains[i].second);
        }

        // Calculate threshold
        int threshold = minGain + alpha * (maxGain - minGain);

        // Select vertices with gain above threshold
        vector<int> RCL;
        for (int i = 0; i < gains.size(); i++) {
            if (gains[i].second >= threshold) {
                RCL.push_back(unassigned_vertices[gains[i].first]);
            }
        }

        if(!RCL.empty()) {
            int random_index = rand() % RCL.size();
            int selected_vertex = RCL[random_index];
            
            int sigma_S = 0;
            int sigma_S_bar = 0;

            for(int j = 0; j < S_bar.size(); j++) {
                sigma_S += edges[selected_vertex][S_bar[j]];
            }

            for(int j = 0; j < S.size(); j++) {
                sigma_S_bar += edges[selected_vertex][S[j]];
            }

            if(sigma_S > sigma_S_bar) {
                S.push_back(selected_vertex);
            } else {
                S_bar.push_back(selected_vertex);
            }

            
            // Find and remove the selected vertex from unassigned_vertices
            auto it = find(unassigned_vertices.begin(), unassigned_vertices.end(), selected_vertex);
            if (it != unassigned_vertices.end()) {
                unassigned_vertices.erase(it);
            }
        }
        
    }

    max_cut_Graph.first = S;
    max_cut_Graph.second = S_bar;

    return max_cut_Graph;

}


int GRASP(int vertices, vector<vector<int>> &edges, int max_iterations = 10)
{

    int cut_weight = 0;
    int max_cut_weight = 0;

    for (int i = 0; i < max_iterations; i++)
    {
        pair<vector<int>, vector<int>> max_cut_graph = SemiGreedyMaxCut(vertices, edges);

        cut_weight = calculate_cut_weight(max_cut_graph, edges);

        // Local Search
        int current_cut_weight = LocalSearch(max_cut_graph, edges, cut_weight);

        max_cut_weight = max(max_cut_weight, current_cut_weight);
    }

    return max_cut_weight;
}

pair<vector<int>, vector<int>> GreedyMaxCut(int vertices, vector<vector<int>> &edges)
{

    pair<vector<int>, vector<int>> max_cut_Graph;

    vector<int> S;
    vector<int> S_bar;

    pair<int, int> max_edge = find_max_edge(edges, vertices);

    S.push_back(max_edge.first);
    S_bar.push_back(max_edge.second);

    for (int i = 1; i <= vertices; i++)
    {
        if (i != max_edge.first && i != max_edge.second)
        {
            int sigma_S = 0;
            int sigma_S_bar = 0;

            // assume current vertex is in S

            for (int j = 0; j < S_bar.size(); j++)
            {
                sigma_S += edges[i][S_bar[j]];
            }

            // assume current vertex is in S_bar
            for (int j = 0; j < S.size(); j++)
            {
                sigma_S_bar += edges[i][S[j]];
            }

            if (sigma_S > sigma_S_bar)
            {
                S.push_back(i);
            }
            else
            {
                S_bar.push_back(i);
            }
        }
    }

    max_cut_Graph.first = S;
    max_cut_Graph.second = S_bar;

    return max_cut_Graph;
}


// int main()
// {
//     // Display menu for algorithm selection
//     cout << "Choose an algorithm:" << endl;
//     cout << "1. Greedy MaxCut" << endl;
//     cout << "2. Semi-Greedy MaxCut" << endl;
//     cout << "3. Local Search" << endl;
//     cout << "4. GRASP" << endl;
//     cout << "5. Randomized MaxCut" << endl;
    
//     int choice;
//     cin >> choice;
    
//     // Set up parameters based on algorithm choice
//     int iterations = 1;
//     double alpha = 0.5;
    
//     if (choice == 3) { // Local Search
//         cout << "Enter number of iterations: ";
//         cin >> iterations;
//     } else if (choice == 4) { // GRASP
//         cout << "Enter number of iterations: ";
//         cin >> iterations;
//     } else if (choice == 2) { // Semi-Greedy
//         cout << "Enter alpha value (0-1): ";
//         cin >> alpha;
//     }
    
//     // Process each graph file in the set1 directory
//     string directory = "graph_GRASP/set1/";
//     for (int fileNum = 1; fileNum <= 54; fileNum++) {
//         string filename = directory + "g" + to_string(fileNum) + ".rud";
//         ifstream file(filename);
        
//         if (!file.is_open()) {
//             cerr << "Could not open file: " << filename << endl;
//             continue;
//         }
        
//         int vertices, edge_number;
//         file >> vertices >> edge_number;
        
//         vector<vector<int>> edges(vertices + 1, vector<int>(vertices + 1, 0));
        
//         for (int i = 0; i < edge_number; i++) {
//             int u, v, w;
//             file >> u >> v >> w;
//             edges[u][v] = w;
//             edges[v][u] = w;
//         }
        
//         file.close();
        
//         // Execute the chosen algorithm and display results
//         cout << "Graph " << fileNum << " (" << vertices << " vertices, " << edge_number << " edges): ";
        
//         int result = 0;
        
//         switch (choice) {
//             case 1: { // Greedy MaxCut
//                 pair<vector<int>, vector<int>> max_cut_graph = GreedyMaxCut(vertices, edges);
//                 result = calculate_cut_weight(max_cut_graph, edges);
//                 cout << "Greedy MaxCut result: " << result << endl;
//                 break;
//             }
//             case 2: { // Semi-Greedy MaxCut
//                 pair<vector<int>, vector<int>> max_cut_graph = SemiGreedyMaxCut(vertices, edges, alpha);
//                 result = calculate_cut_weight(max_cut_graph, edges);
//                 cout << "Semi-Greedy MaxCut result (alpha=" << alpha << "): " << result << endl;
//                 break;
//             }
//             case 3: { // Local Search
//                 int total_weight = 0;
//                 for (int i = 0; i < iterations; i++) {
//                     pair<vector<int>, vector<int>> max_cut_graph = SemiGreedyMaxCut(vertices, edges);
//                     int cut_weight = calculate_cut_weight(max_cut_graph, edges);
//                     int improved_weight = LocalSearch(max_cut_graph, edges, cut_weight);
//                     total_weight += improved_weight;
//                 }
//                 result = total_weight / iterations;
//                 cout << "Local Search result (avg of " << iterations << " iterations): " << result << endl;
//                 break;
//             }
//             case 4: { // GRASP
//                 result = GRASP(vertices, edges, iterations);
//                 cout << "GRASP result (" << iterations << " iterations): " << result << endl;
//                 break;
//             }
//             case 5: { // Randomized MaxCut
//                 result = randomized_MaxCut(vertices, edges);
//                 cout << "Randomized MaxCut result: " << result << endl;
//                 break;
//             }
//             default:
//                 cout << "Invalid choice!" << endl;
//                 return 1;
//         }
//     }
    
//     return 0;
// }

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Create output file for the table data
    ofstream tableData("maxcut_table.csv");
    tableData << "Name,|V| or n,|E| or m,Simple Randomized,Simple Greedy,Semi-greedy-1,Simple local iterations,Simple local avg,GRASP iterations,GRASP best\n";
    
    // Set parameters
    double alpha = 0.3; // Alpha for semi-greedy
    int local_iterations = 20; 
    int grasp_iterations = 20;
    
    // Process all 54 graph files
    string directory = "graph_GRASP/set1/";
    
    // Create a single chart data file
    ofstream chartData("maxcut_chart.csv");
    chartData << "Graph,Randomized,Greedy,Semi-Greedy,GRASP,Local Search\n";
    
    
    for (int fileNum = 1; fileNum <= 54; fileNum ++) {
        string filename = directory + "g" + to_string(fileNum) + ".rud";
        ifstream file(filename);
        
        if (!file.is_open()) {
            cerr << "Could not open file: " << filename << endl;
            continue;
        }
        
        int vertices, edge_number;
        file >> vertices >> edge_number;
        
        vector<vector<int>> edges(vertices + 1, vector<int>(vertices + 1, 0));
        
        for (int i = 0; i < edge_number; i++) {
            int u, v, w;
            file >> u >> v >> w;
            edges[u][v] = w;
            edges[v][u] = w;
        }
        
        file.close();
        
        cout << "Processing Graph G" << fileNum << " (" << vertices << " vertices, " << edge_number << " edges)..." << endl;
        
        
        // 1. Randomized MaxCut
        int randomized_result = randomized_MaxCut(vertices, edges);
        
        // 2. Greedy MaxCut
        pair<vector<int>, vector<int>> greedy_graph = GreedyMaxCut(vertices, edges);
        int greedy_result = calculate_cut_weight(greedy_graph, edges);
        
        // 3. Semi-Greedy MaxCut
        pair<vector<int>, vector<int>> semi_greedy_graph = SemiGreedyMaxCut(vertices, edges, alpha);
        int semi_greedy_result = calculate_cut_weight(semi_greedy_graph, edges);
        
        // 4. Local Search (with multiple iterations)
        int local_total = 0;
        int local_best = 0;
        for (int i = 0; i < local_iterations; i++) {
            pair<vector<int>, vector<int>> base_graph = SemiGreedyMaxCut(vertices, edges);
            int base_weight = calculate_cut_weight(base_graph, edges);
            int improved_weight = LocalSearch(base_graph, edges, base_weight);
            local_total += improved_weight;
            local_best = max(local_best, improved_weight);
        }
        int local_avg = local_total / local_iterations;
        
        // 5. GRASP
        int grasp_best = GRASP(vertices, edges, grasp_iterations); // Call GRASP once with all iterations
        
        // Write results to both CSVs at once
        tableData << "G" << fileNum << "," 
                 << vertices << "," 
                 << edge_number << "," 
                 << randomized_result << "," 
                 << greedy_result << "," 
                 << semi_greedy_result << "," 
                 << local_iterations << "," 
                 << local_avg << "," 
                 << grasp_iterations << "," 
                 << grasp_best << "\n";
                 
        chartData << "G" << fileNum << "," 
                 << randomized_result << "," 
                 << greedy_result << "," 
                 << semi_greedy_result << "," 
                 << grasp_best << ","  // Use grasp_best here directly
                 << local_avg << "\n";
                 
        cout << "Completed G" << fileNum << endl;
    }
    
    tableData.close();
    chartData.close();
    cout << "Table data saved to maxcut_table.csv" << endl;
    cout << "Chart data saved to maxcut_chart.csv" << endl;
    
    return 0;
}