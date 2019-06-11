/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/* 
Descrition:
给定一个数字三角形，找到从顶部到底部的最小路径和。每一步可以移动到下面一行的相邻数字上。

[2],
[3,4],
[6,5,7],
[4,1,8,3]
*/

/*
Result:

*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int solveShortestPath(const vector<vector<int>>& triangle) {
        const int row = triangle.size();
        vector<int> v(row, 0);
        vector<vector<int>> cost(row, v);

        cost[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++) {
            for (int j = 0; j <= i; j++) {
                int lower = max(0, j - 1);
                int upper = min(j, i - 1);
                cost[i][j] = min(cost[i - 1][lower], cost[i - 1][upper]) + triangle[i][j];
            }
        }

        int min_cost = INT_MAX;
        for (int i = 0; i < row; i++) {
            if (cost[row - 1][i] < min_cost) {
                min_cost = cost[row - 1][i];
            }
        }
        return min_cost;
    }
};


int main() {
    vector<vector<int>> v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    std::cout << Solution().solveShortestPath(v) << std::endl;
    return 0;
}
