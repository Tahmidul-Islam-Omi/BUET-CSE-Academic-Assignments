#include <bits/stdc++.h>

using namespace std;

void knapSack_Solve(int n, int w, double maxValue, vector<int> weight, vector<int> value)
{

    vector<vector<int>> dp(n + 1, vector<int>(maxValue + 1, 10000));


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    // knapsack problem polytime approximation scheme

    for (int i = 0; i <= n; i++)
    {
        for (int v = 0; v <= maxValue; v++)
        {

            // cout << "Hello" << endl;

            if (v <= 0)
            {
                // cout << "Hi2" << endl;
                dp[i][v] = 0;
            }

            else if (i == 0 && v > 0)
            {
                // cout << "HiBye" << endl;
                dp[i][v] = 10000;
            }

            else
            {
                // cout << "Hi3" << endl;
                if (v < value[i])
                {
                    dp[i][v] = dp[i - 1][v];
                }
                else
                {
                    dp[i][v] = min(dp[i - 1][v], dp[i - 1][v - value[i]] + weight[i]);
                }
                // dp[i][v] = min(dp[i - 1][v], dp[i - 1][v - value[i]] + weight[i]);
                //  cout << "Hi4" << endl;
            }
        }
    }



    int ans = 0;
    int Used_Weight = 0;

    cout << "Ans " << ans << endl;

    for (int v = 0; v <= maxValue; v++)
    {
        //cout << "Before" << endl;
        //cout << ans << " " << Used_Weight << endl;

        // std::cout << v << " " << dp[n][v] << endl;
        if (dp[n][v] <= w && dp[n][v] > 0)
        {
            //cout << "After" << endl;
            cout << ans << " " << Used_Weight << endl;
            
            ans = v;
            Used_Weight = dp[n][v];
        }

    }

    std::cout << "ans is " << ans << endl;
    std::cout << Used_Weight << endl;
}

int main()
{

    int n, w;
    cin >> n >> w;

    vector<int> weight(n + 1), value(n + 1);

    int maxValue = -100000;

    for (int i = 1; i <= n; i++)
    {
        cin >> value[i] >> weight[i];
        maxValue = max(maxValue, value[i]);
    }

    maxValue = maxValue * n;

    knapSack_Solve(n, w, maxValue, weight, value);

    double eps = 0.5;

    int Vmax = maxValue / n;

    double theta = double((eps * Vmax) / (2 * n));
    cout << theta << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    //Vmax = 0;


    for (int i = 1; i <= n; i++)
    {
        value[i] = ceil((double)value[i] / (double)theta);
        //Vmax = max(Vmax, value[i]);
        //cout << value[i] << " ";
    }

    //cout << "Hi" << endl;
    cout << Vmax << endl;

    cout << endl;

    knapSack_Solve(n, w, Vmax, weight, value);

    return 0;
}
