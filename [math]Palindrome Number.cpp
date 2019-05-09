/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

/*
Result:
Runtime: 16 ms, faster than 99.47% of C++ online submissions for Palindrome Number.
Memory Usage: 8.2 MB, less than 99.33% of C++ online submissions for Palindrome Number.
*/

/*
Analysis:
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        const int len = str.size();
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().isPalindrome(-121) << endl;
    return 0;
}
