/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

/*
Result:
Runtime: 44 ms, faster than 32.48% of C++ online submissions for Range Sum Query - Immutable.
Memory Usage: 17.5 MB, less than 13.00% of C++ online submissions for Range Sum Query - Immutable.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        _sum = new vector<int>(size + 1, 0);
        for (int i = 0; i < size; i++) {
            (*_sum)[i + 1] = (*_sum)[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return (*_sum)[j + 1] - (*_sum)[i];
    }

private:
    vector<int>* _sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


int main() {
    vector<int> v = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(v);
    cout << obj->sumRange(0, 2) << endl;
    cout << obj->sumRange(2, 5) << endl;
    cout << obj->sumRange(0, 5) << endl;
    return 0;
}
