/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of
the result is returned.

Example 1:
Input: 4
Output: 2

Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/

/*
Result:
Runtime: 12 ms, faster than 35.22% of C++ online submissions for Sqrt(x).
Memory Usage: 8.1 MB, less than 75.00% of C++ online submissions for Sqrt(x).
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int mySqrt(int x) {
        long long int a = 0;
        long long int b = x;
        long long int i = (a + b) / 2;
        while (a != b) {
            if (i * i < x && ((i + 1) * (i + 1) <= x)) {
                a = i + 1;
            } else if (i * i > x) {
                b = i;
            } else {
                a = i;
                b = i;
            }
            i = (a + b) / 2;
        }
        return (int)i;
    }
};


int main() {
    cout << Solution().mySqrt(4) << endl;
    cout << Solution().mySqrt(8) << endl;
    cout << Solution().mySqrt(1) << endl;
    return 0;
}
