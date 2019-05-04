/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

/*
Result:
Runtime: 36 ms, faster than 27.46% of C++ online submissions for Missing Number.
Memory Usage: 10.1 MB, less than 9.84% of C++ online submissions for Missing Number.
*/

/*
Analysis:
Time Complexity: O(Nlog(N))
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (const int& num : nums) {
            if (res != num)
                break;
            res++;
        }
        return res;
    }
};

int main() {
    vector<int> v = {9,6,4,2,3,5,7,0,1};
    cout << Solution().missingNumber(v) << endl;
    return 0;
}
