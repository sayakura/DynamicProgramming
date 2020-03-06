#include <iostream>
#include <vector>

using namespace std;

int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    int n = profits.size(); // # of items
    // edge case checking 
    if (capacity <= 0 || !weights.size() || weights.size() != profits.size())
        return 0;

    vector<vector<int> > dp(n, vector<int>(capacity + 1));

    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    for (int c = 0; c <= capacity; c++) 
        dp[0][c] = weights[0] <= c ? profits[0] : 0;
    // int m = weights.size();
    for (int i = 1; i < n; i++) {
        for (int c = 1; c <= capacity; c++) {
            int p1 = 0, p2 = 0;
            if (weights[i] <= c)
                p1 = profits[i] + dp[i - 1][c - weights[i]];
            p2 = dp[i - 1][c];
            dp[i][c] = max(p1, p2);
        }
    }
    return dp[n - 1][capacity];
}

int main(void) {
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    int maxProfit = solveKnapsack(profits, weights, 7);
    cout << maxProfit << endl;
    return 0;
}