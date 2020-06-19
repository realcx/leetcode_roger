/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#include "common/vector_util.hpp"

using namespace std;

/* 
Descrition:
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error,
one of the numbers in the set got duplicated to another number in the set,
which results in repetition of one number and loss of another number.
Given an array nums representing the data status of this set after the error.
Your task is to firstly find the number occurs twice and then find the number that is missing.
Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/

/*
Result:
Runtime: 48 ms, faster than 48.88% of C++ online submissions for Set Mismatch.
Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Set Mismatch.
*/

/*
Analysis:
Time Complexity: O(Nlog(N))
Space Complexity: O(log(N))
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicated_num = 0, missing_num = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                duplicated_num = nums[i];
            if (nums[i] + 1 < nums[i + 1]) {
                missing_num = nums[i] + 1;
            }
        }
        if (*(nums.end() - 1) != nums.size())
            missing_num = nums.size();
        vector<int> v = {duplicated_num, missing_num};
        return v;
    }
};


int main() {
    vector<int> v = {3,2,3,4,6,5};
    VectorUtil::print_vector1d(Solution().findErrorNums(v));
    return 0;
}
