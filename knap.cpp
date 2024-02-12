/*#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    int max_value = knapsack(capacity, weights, values);

    cout << "Maximum value: " << max_value << endl;

    return 0;
}
*/
#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Base case: If there are no items or the capacity is 0, the value is 0.
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // If the weight of the nth item is more than the current capacity,
    // then this item cannot be included in the knapsack.
    if (weights[n - 1] > capacity) {
        return knapsack(capacity, weights, values, n - 1);
    }

    // Return the maximum of two cases:
    // 1. Include the nth item in the knapsack
    // 2. Exclude the nth item from the knapsack
    return max(values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1),
               knapsack(capacity, weights, values, n - 1));
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;
    int n = weights.size();

    int max_value = knapsack(capacity, weights, values, n);

    cout << "Maximum value: " << max_value << endl;

    return 0;
}

