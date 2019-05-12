/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some
integers i >= 0 and j >= 0.
Return a list of all powerful integers that have value less than or equal to bound.
You may return the answer in any order.  In your answer, each value should occur at most once.

Example 1:
Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2

Example 2:
Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]

Note:
1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Powerful Integers.
Memory Usage: 8.6 MB, less than 98.99% of C++ online submissions for Powerful Integers.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i = 0, j = 0;
        set<int> s;
        while (pow(x, i) + 1 <= bound) {
            for (j = 0; pow(x, i) + pow(y, j) <= bound; j++) {
                s.insert(pow(x, i) + pow(y, j));
                if (y == 1) break;
            }
            i++;
            if (x == 1) break;
        }
        vector<int> v(s.begin(), s.end());
        return v;
    }
};


int main() {
    VectorUtil::print_vector1d(Solution().powerfulIntegers(3, 5, 15));
    VectorUtil::print_vector1d(Solution().powerfulIntegers(2, 3, 10));
    return 0;
}
