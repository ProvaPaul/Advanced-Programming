#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, weights, values, n);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
/*
Enter the number of items: 4
Enter the weights of each item:
2 1 3 4
Enter the values of each item:
12 10 20 25
Enter the maximum weight capacity of the knapsack: 5

*/









































































