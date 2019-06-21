/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

/*
Result:
Runtime: 4 ms, faster than 98.36% of C++ online submissions for Target Sum.
Memory Usage: 8.7 MB, less than 61.90% of C++ online submissions for Target Sum.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        int sum = 0;
        for (const int& num : nums) {
            sum += num;
        }
        if (abs(S) > sum || (S + sum) & 1) {
            return 0;
        }
        const int sum_p = (sum + S) / 2;

        vector<vector<int>> amount(size, vector<int>(sum_p + 1, 0));
        if (nums[0] == 0) {
            amount[0][0] = 2;
        } else {
            amount[0][0] = 1;
        }
        for (int j = 1; j <= sum_p; j++) {
            if (nums[0] == j) {
                amount[0][j] = 1;
            }
        }

        for (int i = 1; i < size; i++) {
            for (int j = 0; j <= sum_p; j++) {
                if (j >= nums[i]) {
                    amount[i][j] = amount[i - 1][j] + amount[i - 1][j - nums[i]];
                } else {
                    amount[i][j] = amount[i - 1][j];
                }
            }
        }

        return amount[size - 1][sum_p];
    }
};


class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        int sum = 0;
        for (const int& num : nums) {
            sum += num;
        }
        if (abs(S) > sum || (S + sum) & 1) {
            return 0;
        }
        const int sum_p = (sum + S) / 2;

        vector<int> amount(sum_p + 1, 0);
        amount[0] = 1;
        for (int i = 0; i < size; i++) {
            for (int j = sum_p; j >= nums[i]; j--) {
                amount[j] += amount[j - nums[i]];
            }
        }
        return amount[sum_p];
    }
};


int main() {
    vector<int> v1 = {1, 1, 1, 1, 1};
    cout << Solution2().findTargetSumWays(v1, 3) << endl;
    vector<int> v2 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    cout << Solution2().findTargetSumWays(v2, 1) << endl;
    vector<int> v3 = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    cout << Solution2().findTargetSumWays(v3, 2) << endl;
    return 0;
}
