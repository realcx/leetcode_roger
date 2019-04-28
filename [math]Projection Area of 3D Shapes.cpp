/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.
Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
Now we view the projection of these cubes onto the xy, yz, and zx planes.
A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane. 
Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
Return the total area of all three projections.

Example 1:
Input: [[2]]
Output: 5

Example 2:
Input: [[1,2],[3,4]]
Output: 17
Explanation: 
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.

Example 3:
Input: [[1,0],[0,2]]
Output: 8

Example 4:
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 14

Example 5:
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 21
*/

/*
Result:

*/

/*
Analysis:
Time Complexity: O(N^2)
Space Complexity: O(1)
*/


class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int grid_row = grid.size();
        int grid_col = grid[0].size();

        vector<int> v(grid_row, 0);
        vector<vector<int>> grid_transpose(grid_col, v);
        for (int row = 0; row < grid_row; row++)
            for (int col = 0; col < grid_col; col++)
                grid_transpose[col][row] = grid[row][col];

        int result = get_area_from_top(grid);
        for (const auto& vect : grid)
            result += get_area_from_side(vect);
        for (const auto& vect : grid_transpose)
            result += get_area_from_side(vect);

        return result;
    }

    int get_area_from_side(vector<int> vect) {
        int max_value = 0;
        for (const int& value : vect) {
            if (value > max_value)
                max_value = value;
        }
        return max_value;
    }

    int get_area_from_top(vector<vector<int>>& grid) {
        int grid_row = grid.size();
        int grid_col = grid[0].size();
        int value = 0;
        for (int row = 0; row < grid_row; row++)
            for (int col = 0; col < grid_col; col++)
                if (grid[row][col] > 0)
                    value++;
        return value;
    }
};


int main() {
    std::vector<std::vector<int>> v = {{1, 2}, {3, 4}};
    cout << Solution().projectionArea(v) << endl;
    return 0;
}
