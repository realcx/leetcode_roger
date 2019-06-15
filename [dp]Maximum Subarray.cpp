/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has
the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

/*
Result:
Runtime: 4 ms, faster than 99.52% of C++ online submissions for Maximum Subarray.
Memory Usage: 9.5 MB, less than 41.01% of C++ online submissions for Maximum Subarray.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> sum(size, 0);
        sum[0] = nums[0];
        for (int i = 1; i < size; i++) {
            sum[i] = max(sum[i - 1] + nums[i], nums[i]);
        }

        int max_sum = sum[0];
        for (int i = 1; i < size; i++) {
            if (sum[i] > max_sum) {
                max_sum = sum[i];
            }
        }
        return max_sum;
    }
};


int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(v) << endl;
    return 0;
}
