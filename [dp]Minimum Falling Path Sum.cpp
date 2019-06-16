/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Given a square array of integers A, we want the minimum sum of a falling path through A.
A falling path starts at any element in the first row, and chooses one element from each row.
The next row's choice must be in a column that is different from the previous row's column by at most one.

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

Note:
1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
*/

/*
Result:
Runtime: 16 ms, faster than 70.44% of C++ online submissions for Minimum Falling Path Sum.
Memory Usage: 10.3 MB, less than 16.75% of C++ online submissions for Minimum Falling Path Sum.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size = A.size();
        int lower, upper;
        vector<int> v(size, 0);
        vector<vector<int>> sum(size, v);

        if (size < 1)
            return 0;

        for (int j = 0; j < size; j++) {
            sum[0][j] = A[0][j];
        }
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size; j++) {
                lower = max(j - 1, 0);
                upper = min(j + 1, size - 1);
                sum[i][j] = min(min(sum[i - 1][lower], sum[i - 1][j]),
                                min(sum[i - 1][upper], sum[i - 1][j])) + A[i][j];
            }
        }

        int max_sum = sum[size - 1][0];
        for (int j = 0; j < size; j++) {
            if (sum[size - 1][j] < max_sum) {
                max_sum = sum[size - 1][j];
            }
        }
        return max_sum;
    }
};


int main() {
    vector<vector<int>> v = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << Solution().minFallingPathSum(v) << endl;
    return 0;
}
