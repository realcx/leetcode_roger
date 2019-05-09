/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner,
and (x2, y2) are the coordinates of its top-right corner.
Two rectangles overlap if the area of their intersection is positive.
To be clear, two rectangles that only touch at the corner or edges do not overlap.
Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:
Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true

Example 2:
Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false

Notes:
Both rectangles rec1 and rec2 are lists of 4 integers.
All coordinates in rectangles will be between -10^9 and 10^9.
*/

/*
Result:
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Rectangle Overlap.
Memory Usage: 8.4 MB, less than 65.67% of C++ online submissions for Rectangle Overlap.
*/

/*
Analysis:
Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (is_interaction(rec2[0], rec2[2], rec1[0], rec1[2]) &&
            is_interaction(rec2[1], rec2[3], rec1[1], rec1[3])) {
            return true;
        }
        return false;
    }

    bool is_interaction(const int& xa,
                        const int& xb,
                        const int& x1,
                        const int& x2) {
        if ((xa > x1 && xa < x2) || (xb > x1 && xb < x2) || (xa <= x1 && xb >= x2)) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution2 {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (min(rec1[2], rec2[2]) - max(rec1[0], rec1[0]) &&
                min(rec1[3], rec2[3]) - max(rec1[1], rec1[1]));
    }
};

int main() {
    vector<int> v1 = {7, 8, 13, 15}, v2 = {10, 8, 12, 20};
    cout << Solution2().isRectangleOverlap(v1, v2) << endl;
    return 0;
}
