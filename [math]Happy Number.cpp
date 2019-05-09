/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/* 
Descrition:
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer,
replace the number by the sum of the squares of its digits, and repeat the process until the number
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example: 
Input: 19
Output: true

Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

/*
Result:
Runtime: 8 ms, faster than 33.28% of C++ online submissions for Happy Number.
Memory Usage: 8.7 MB, less than 5.68% of C++ online submissions for Happy Number.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution {
public:
    bool isHappy(int n) {
        set<int> data_set;
        while (n != 1) {
            string n_str = to_string(n);
            n = 0;
            for (const auto& c : n_str)
                n += (c - '0') * (c - '0');
            if (data_set.find(n) == data_set.end()) {
                data_set.insert(n);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().isHappy(19) << endl;
    return 0;
}
