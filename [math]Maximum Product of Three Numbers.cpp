/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.hpp"

using namespace std;

/* 
Descrition:
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6

Example 2:
Input: [1,2,3,4]
Output: 24

Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

/*
Result:
Runtime: 68 ms, faster than 54.75% of C++ online submissions for Maximum Product of Three Numbers.
Memory Usage: 11 MB, less than 96.48% of C++ online submissions for Maximum Product of Three Numbers.
*/

/*
Analysis:
Time Complexity: O(Nlog(N))
Space Complexity: O(log(N))
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int len = nums.size();
        int product = 0.0;
        if (nums[len - 1] < 0) {
            product = nums[0] * nums[1] * nums[2];
        } else if (nums[0] > 0) {
            product = nums[len - 1] * nums[len - 2] * nums[len - 3];
        } else {
            product = max(nums[0] * nums[1] * nums[len - 1],
                          nums[len - 1] * nums[len - 2] * nums[len - 3]);
        }
        return product;
    }
};


int main() {
    vector<int> v = {1,2,3,4};
    cout << Solution().maximumProduct(v) << endl;
    return 0;
}
