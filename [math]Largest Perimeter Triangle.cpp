/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area,
formed from 3 of these lengths.
If it is impossible to form any triangle of non-zero area, return 0.

Example 1:
Input: [2,1,2]
Output: 5

Example 2:
Input: [1,2,1]
Output: 0

Example 3:
Input: [3,2,3,4]
Output: 10

Example 4:
Input: [3,6,2,3]
Output: 8

Note:
3 <= A.length <= 10000
1 <= A[i] <= 10^6
*/

/*
Result:
Runtime: 56 ms, faster than 72.69% of C++ online submissions for Largest Perimeter Triangle.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Largest Perimeter Triangle.
*/

/*
Analysis:
Time Complexity: O(N*log(N))
Space Complexity: O(1)
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        std::sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; --i) {
            if (A[i] - A[i - 1] < A[i - 2]) {
                return (A[i] + A[i - 1] + A[i - 2]);
            }
        }
        return 0;
    }
};


int main() {
    vector<int> v = {3,6,2,3};
    cout << Solution().largestPerimeter(v) << endl;
    return 0;
}
