/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/* 
Descrition:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*
Result:
Runtime: 40 ms, faster than 63.66% of C++ online submissions for Roman to Integer.
Memory Usage: 10.9 MB, less than 97.82% of C++ online submissions for Roman to Integer.
*/

/*
Analysis:
Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman_map;
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;

        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && is_principle(s[i], s[i + 1])) {
                res += roman_map[s[i + 1]] - roman_map[s[i]];
                i++;
            } else {
                res += roman_map[s[i]];
            }
        }
        return res;
    }

    bool is_principle(const char& a, const char& b) {
        if ((a == 'I' && (b == 'V' || b == 'X')) ||
            (a == 'X' && (b == 'L' || b == 'C')) ||
            (a == 'C' && (b == 'D' || b == 'M')))
            return true;
        return false;
    }
};


int main() {
    string s("MCMXCIV");
    cout << Solution().romanToInt(s) << endl;
    return 0;
}
