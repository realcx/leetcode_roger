/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#include "common/vector_util.hpp"

using namespace std;

/* 
Descrition:
You are given coins of different denominations and a total amount of money amount. Write a function
to compute the fewest number of coins that you need to make up that amount. If that amount of money
cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
*/

/*
Result:
Runtime: 60 ms, faster than 38.55% of C++ online submissions for Coin Change.
Memory Usage: 40.7 MB, less than 10.56% of C++ online submissions for Coin Change.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector <int>> num(size ,vector<int>(amount + 1, 0));

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                num[0][j] = j / coins[0];
            } else {
                num[0][j] = INT_MAX;
            }
        }
        for (int i = 1; i < size; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j - coins[i] >= 0) {
                    num[i][j] = min(num[i - 1][j], num[i][j - coins[i]] + 1);
                } else {
                    num[i][j] = num[i - 1][j];
                }
            }
        }

        VectorUtil::print_vector2d(num);

        int res = num[size - 1][amount] == INT_MAX ? -1 : num[size - 1][amount];
        return res;
    }
};


int main() {
    vector<int> v1 = {1, 2, 5};
    cout << Solution().coinChange(v1, 11) << endl;
    vector<int> v2 = {2};
    cout << Solution().coinChange(v2, 3) << endl;
    vector<int> v3 = {1, 2};
    cout << Solution().coinChange(v3, 2) << endl;
    return 0;
}
