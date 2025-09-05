#include <iostream>
#include <vector>
#include <algorithm>

long long maxCoins(std::vector<std::vector<int>>& coins, int k) {
    if (coins.empty()) {
        return 0;
    }

    std::sort(coins.begin(), coins.end());

    long long maxTotalCoins = 0;
    for (int start = 1; ; ++start) {
        long long currentTotalCoins = 0;
        int currentCount = 0;

        for (int j = 0; j < k; ++j) {
            for (const auto& coin : coins) {
                if (coin[0] <= start + j && start + j <= coin[1]) {
                    currentTotalCoins += coin[2];
                    break; // Move to the next bag in the window
                }
            }
        }

        if (currentTotalCoins > 0) {
            maxTotalCoins = std::max(maxTotalCoins, currentTotalCoins);
        }

        //Optimization: break when start is too far away to get k consecutive.
        if (coins.size() > 0 && start > coins.back()[1]) {
            break;
        }

        //Optimization: break if there are no more coins to be found.
        if(coins.size() > 0 && start + k -1 < coins[0][0] && maxTotalCoins > 0){
            break;
        }

        //Optimization: if the start is too far from the last coin, and we have already found a solution, then exit.
        if (coins.size() > 0 && start > coins.back()[1]-k+1 && maxTotalCoins >0){
            break;
        }
    }

    return maxTotalCoins;
}

int main() {
    std::vector<std::vector<int>> coins1 = {{8, 10, 1}, {1, 3, 2}, {5, 6, 4}};
    int k1 = 4;
    std::cout << "Example 1: " << maxCoins(coins1, k1) << std::endl;

    std::vector<std::vector<int>> coins2 = {{1, 10, 3}};
    int k2 = 2;
    std::cout << "Example 2: " << maxCoins(coins2, k2) << std::endl;

    std::vector<std::vector<int>> coins3 = {{1, 2, 1}, {4, 5, 2}, {7, 8, 3}};
    int k3 = 3;
    std::cout << "Example 3: " << maxCoins(coins3, k3) << std::endl;

    std::vector<std::vector<int>> coins4 = {{1, 1000000000, 1}};
    int k4 = 1000000;
    std::cout << "Example 4: " << maxCoins(coins4, k4) << std::endl;

    std::vector<std::vector<int>> coins5 = {};
    int k5 = 10;
    std::cout << "Example 5: " << maxCoins(coins5, k5) << std::endl;

    std::vector<std::vector<int>> coins6 = {{1, 10, 1}, {20, 30, 1}};
    int k6 = 15;
    std::cout << "Example 6: " << maxCoins(coins6, k6) << std::endl;

    return 0;
}