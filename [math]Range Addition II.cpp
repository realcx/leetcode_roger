/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Given an m * n matrix M initialized with all 0's and several update operations.
Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b,
which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
You need to count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: 
m = 3, n = 3
operations = [[2,2],[3,3]]
Output: 4

Explanation: 
Initially, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

After performing [2,2], M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

After performing [3,3], M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

So the maximum integer in M is 2, and there are four of it in M. So return 4.
Note:
The range of m and n is [1,40000].
The range of a is [1,m], and the range of b is [1,n].
The range of operations size won't exceed 10,000.
*/

/*
Result:
Runtime: 12 ms, faster than 97.67% of C++ online submissions for Range Addition II.
Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Range Addition II.
*/

/*
Analysis:
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_row = m;
        int min_col = n;
        for (const auto& v : ops) {
            min_row = min(v[0], min_row);
            min_col = min(v[1], min_col);
        }
        return min_col * min_row;
    }
};


int main() {
    vector<vector<int>> v = {{2, 2}, {3, 3}};
    cout << Solution().maxCount(3, 3, v) << endl;
    return 0;
}
