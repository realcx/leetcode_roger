/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
*/

/*
Result:
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Add Digits.
Memory Usage: 8.4 MB, less than 7.44% of C++ online submissions for Add Digits.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution {
public:
    int addDigits(int num) {
        if (num / 10 > 0) {
            return addDigits(num / 10 + num % 10);
        } else {
            return num;
        }
    }
};


int main() {
    cout << Solution().addDigits(38) << endl;
    return 0;
}
