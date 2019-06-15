/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
You are a professional robber planning to rob houses along a street. Each house has a certain amount
of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses
have security system connected and it will automatically contact the police if two adjacent houses
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

/*
Result:
Runtime: 4 ms, faster than 83.83% of C++ online submissions for House Robber.
Memory Usage: 8.7 MB, less than 41.79% of C++ online submissions for House Robber.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;
        else if (size == 1)
            return nums[0];
        else if (size == 2)
            return max(nums[0], nums[1]);

        vector<int> amount(size, 0);
        amount[0] = nums[0];
        amount[1] = nums[1];
        amount[2] = nums[0] + nums[2];
        for (int i = 3; i < size; i++) {
            amount[i] = max(amount[i - 2], amount[i - 3]) + nums[i];
        }

        return max(amount[size - 1], amount[size - 2]);
    }
};


int main() {
    vector<int> v1 = {2,7,9,3,1};
    cout << Solution().rob(v1) << endl;
    vector<int> v2 = {1,2,3,1};
    cout << Solution().rob(v2) << endl;
    return 0;
}
