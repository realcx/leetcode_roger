/* g++ origin.cpp -o hello -std=c++11 */

#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.

Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Perfect Number.
Memory Usage: 6.2 MB, less than 5.10% of C++ online submissions for Perfect Number.
*/

/*
Analysis:
Time Complexity: O(NlogN)
Space Complexity: 1
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0 or num == 1) {
            return false;
        }

        int sum = 1;

        for (int i = 2; i < sqrt(num); i++) {
            if (num % i == 0) {
                if (i * i == num) {
                    sum += i;
                } else {
                    sum += i + num / i;
                }
            }
        }

        return sum == num;
    }
};


int main() {
    std::cout << Solution().checkPerfectNumber(28) << std::endl;
    return 0;
}
