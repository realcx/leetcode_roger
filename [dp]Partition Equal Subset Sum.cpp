/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
Given a non-empty array containing only positive integers, find if the array can be partitioned into
two subsets such that the sum of elements in both subsets is equal.
Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

/*
Result:
Runtime: 120 ms, faster than 43.87% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 60.3 MB, less than 7.04% of C++ online submissions for Partition Equal Subset Sum.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for (const int& num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        const int amount = sum / 2;

        vector<vector<int>> value(size, vector<int>(amount + 1, 0));
        for (int j = 0; j <= amount; j++) {
            if (j >= nums[0]) {
                value[0][j] = nums[0];
            } else {
                value[0][j] = 0;
            }
        }

        for (int i = 1; i < size; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j >= nums[i]) {
                    value[i][j] = max(value[i - 1][j - nums[i]] + nums[i], value[i - 1][j]);
                } else {
                    value[i][j] = value[i - 1][j];
                }
            }
        }

        bool res = false;
        if (value[size - 1][amount] == amount)
            res = true;

        VectorUtil::print_vector2d(value);
        return res;
    }
};


int main() {
    vector<int> v1 = {1, 5, 11, 5};
    cout << Solution().canPartition(v1) << endl;
    vector<int> v2 = {3, 3, 3, 4, 5};
    cout << Solution().canPartition(v2) << endl;
    return 0;
}
