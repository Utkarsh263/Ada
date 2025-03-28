#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int n;  // Number of cities
vector<vector<int>> dist;  // Distance matrix
vector<vector<int>> dp;  // Memoization table

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {  // All cities visited
        return dist[pos][0];  // Return to starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];  // Return memoized result
    }

    int minCost = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {  // If city not visited
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
            minCost = min(minCost, newCost);
        }
    }

    return dp[mask][pos] = minCost;  // Store result in DP table
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    dist.assign(n, vector<int>(n));
    dp.assign(1 << n, vector<int>(n, -1));

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int result = tsp(1, 0);  // Start from city 0 with mask 1
    cout << "Minimum travel cost: " << result << endl;

    return 0;
}
