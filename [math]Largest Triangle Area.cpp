/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/* 
Descrition:
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.

Notes:
3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
*/

/*
Result:
Runtime: 8 ms, faster than 98.48% of C++ online submissions for Largest Triangle Area.
Memory Usage: 9.3 MB, less than 81.82% of C++ online submissions for Largest Triangle Area.
*/

/*
Analysis:
Time Complexity: O(N^3)
Space Complexity: O(1)
*/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int len = points.size();
        double max_area = 0.0;
        double area = 0.0;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                for (int k = j + 1; k < len; ++k) {
                    area = get_triangle_area(points[i], points[j], points[k]);
                    max_area = std::max(max_area, area);
                }
            }
        }
        return max_area;
    }

    double get_triangle_area(const vector<int>& a,
                             const vector<int>& b,
                             const vector<int>& c) {
        const double ab = get_length(a, b);
        const double ac = get_length(a, c);
        const double bc = get_length(b, c);
        const double p = 0.5 * (ab + ac + bc);
        return sqrt(p * (p - ab) * (p - ac) * (p - bc));
    }

    double get_length(const vector<int>& a,
                      const vector<int>& b) {
        const double x = a[0] - b[0];
        const double y = a[1] - b[1];
        return sqrt(x * x + y * y);
    }
};


int main() {
    vector<vector<int>> v = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << Solution().largestTriangleArea(v) << endl;
    return 0;
}
