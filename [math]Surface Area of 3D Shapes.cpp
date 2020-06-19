/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.hpp"

using namespace std;

/* 
Descrition:
On a N * N grid, we place some 1 * 1 * 1 cubes.
Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
Return the total surface area of the resulting shapes.

Example 1:
Input: [[2]]
Output: 10

Example 2:
Input: [[1,2],[3,4]]
Output: 34

Example 3:
Input: [[1,0],[0,2]]
Output: 16

Example 4:
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32

Example 5:
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46

Note:
1 <= N <= 50
0 <= grid[i][j] <= 50
*/

/*
Result:
Runtime: 12 ms, faster than 60.75% of C++ online submissions for Surface Area of 3D Shapes.
Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Surface Area of 3D Shapes.
*/

/*
Analysis:
Time Complexity: O(N^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int i, j;
        const int il[4] = {0, 0, -1, 1};
        const int jl[4] = {-1, 1, 0, 0};
        const int len = grid.size();
        for (int row = 0; row < len; ++row) {
            for (int col = 0; col < len; ++col) {
                if (grid[row][col] > 0) {
                    res += 2;   // for top area
                    for (int k = 0; k < 4; ++k) {
                        i = row + il[k];
                        j = col + jl[k];
                        if (i < len && i >= 0 && j < len && j >= 0) {
                            res += std::max(grid[row][col] - grid[i][j], 0);
                        } else {
                            res += grid[row][col];
                        }
                    }
                }
            }
        }
        return res;
    }
};


int main() {
    vector<vector<int>> v = {{1, 2}, {3, 4}};
    cout << Solution().surfaceArea(v) << endl;
    return 0;
}
