// The 0-1 knapsack problem is a classic optimization problem in computer science and combinatorial optimization. The problem can be stated as follows:

// You are given a set of items, each with a weight and a value. You have a knapsack with a maximum weight capacity. Your goal is to select a subset of the items to include in the knapsack in such a way that the total weight does not exceed the capacity of the knapsack, and the total value of the items included is maximized. The constraint here is that you can either take an item (the '1' in 0-1 knapsack) or leave it (the '0' in 0-1 knapsack), meaning you cannot take a fractional amount of an item.

// ```cpp
#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0-1 knapsack problem
int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    // Weight capacity of knapsack
    int W = 50;

    // Values and weights of items
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int n = val.size();

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}

//```

// In this implementation, we use dynamic programming to solve the problem efficiently. We create a 2D array `dp`, where `dp[i][w]` represents the maximum value that can be achieved with the first `i` items and a knapsack of capacity `w`. We fill in this array iteratively, considering each item and each possible weight capacity of the knapsack.

// The time complexity of this solution is O(nW), where n is the number of items and W is the maximum weight capacity of the knapsack.