#include <bits/stdc++.h>
using namespace std;

int solveTSP(vector<vector<int>>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    
    vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));
    dp[0][1] = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int curr = 0; curr < n; curr++) {
            if (dp[curr][mask] == INT_MAX) continue;
            for (int nxt = 0; nxt < n; nxt++) {
                if (!(mask & (1 << nxt))) {
                    int newMask = mask | (1 << nxt);
                    dp[nxt][newMask] = min(dp[nxt][newMask], dp[curr][mask] + cost[curr][nxt]);
                }
            }
        }
    }
    
    int fullMask = (1 << n) - 1;
    int result = INT_MAX;
    for (int last = 1; last < n; last++) {
        result = min(result, dp[last][fullMask] + cost[last][0]);
    }
    
    return result;
}

int main() {
    vector<vector<int>> cost = {{0, 111}, {112, 0}};
    cout << solveTSP(cost) << endl;
    return 0;
}