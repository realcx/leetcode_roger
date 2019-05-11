/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
Memory Usage: 8.3 MB, less than 5.52% of C++ online submissions for Valid Perfect Square.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution1 {
public:
    bool isPerfectSquare(int num) {
        for (long int i = 1; i <= num; i++) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool isPerfectSquare(int num) {
        long int a = 1, b = num, m = 0, sq = 0;
        if (num == 0 || num == 1)
            return true;
        while (b > a + 1) {
            m = a + (b - a) / 2;
            sq = m * m;
            if (sq == num) {
                return true;
            } else if (sq < num) {
                a = m;
            } else {
                b = m;
            }
        }
        return false;
    }
};

int main() {
    cout << Solution2().isPerfectSquare(16) << endl;
    cout << Solution2().isPerfectSquare(14) << endl;
    cout << Solution2().isPerfectSquare(2147483647) << endl;
    return 0;
}
