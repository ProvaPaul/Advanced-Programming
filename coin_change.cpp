#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 20
#define MAX_W 10000
#define INF 99999999
#define EMPTY_VALUE -1

using namespace std;

int C[MAX_N];
int mem[MAX_N][MAX_W];
int n;

int f(int i, int W) {
    if (W < 0) return INF;
    if (i == n) {
        if (W == 0) return 0;
        return INF;
    }

    if (mem[i][W] != EMPTY_VALUE) {
        return mem[i][W];
    }

    int res_1 = 1 + f(i + 1, W - C[i]);
    int res_2 = f(i + 1, W);

    mem[i][W] = (res_1 < res_2) ? 1 : 2;

    return min(res_1, res_2);
}

void printSelectedCoins(int i, int W) {
    if (i == n || W == 0) return;
    if (mem[i][W] == 1) {
        cout << C[i] << " ";
        printSelectedCoins(i + 1, W - C[i]);
    } else {
        printSelectedCoins(i + 1, W);
    }
}

int main() {
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    int sum;
    cout << "Enter the target sum: ";
    cin >> sum;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            mem[i][j] = EMPTY_VALUE;
        }
    }

    int result = f(0, sum);

    if (result == INF) {
        cout << "It is not possible to make the target sum with the given denominations." << endl;
    } else {
        cout << "Minimum number of coins required to make the sum: " << result << endl;
        cout << "Selected coins: ";
        printSelectedCoins(0, sum);
        cout << endl;
    }

    return 0;
}

