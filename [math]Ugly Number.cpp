/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/* 
Descrition:
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:
Input: 6
Output: true
Explanation: 6 = 2 × 3

Example 2:
Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2

Example 3:
Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.

Note:
1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Ugly Number.
Memory Usage: 8.1 MB, less than 24.79% of C++ online submissions for Ugly Number.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution1 {
public:
    bool isUgly(int num) {
        set<int> tmp_set = {2, 3, 5};
        int factor = get_prime_factor(num);
        if (num == 1) 
            return true;
        else if (num <= 0)
            return false;
        else if (tmp_set.find(factor) == tmp_set.end())
            return false;
        else
            return isUgly(num / factor);
        return true;
    }

    int get_prime_factor(const int& num) {
        int i;
        for (i = 2; i <= num; i++) {
            if (num % i == 0)
                break;
        }
        return i;
    }
};

class Solution2 {
public:
    bool isUgly(int num) {
        vector<int> v = {2, 3, 5};
        if (num < 1)
            return false;
        while (num > 1) {
            for (const int& i : v) {
                if (num % i == 0) {
                    num /= i;
                    break;
                }
                if (i == *(v.end() - 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    cout << Solution2().isUgly(6) << endl;
    cout << Solution2().isUgly(8) << endl;
    cout << Solution2().isUgly(14) << endl;
    cout << Solution2().isUgly(-2147483648) << endl;
    return 0;
}
