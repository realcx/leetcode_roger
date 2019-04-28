/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
Also, a self-dividing number is not allowed to contain the digit zero.
Given a lower and upper number bound, output a list of every possible self dividing number,
including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
*/

/*
Result:
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Self Dividing Numbers.
Memory Usage: 8.6 MB, less than 73.68% of C++ online submissions for Self Dividing Numbers.
*/

/*
Analysis:
Time Complexity: O(D), D is the number of integers in the range [L, R]
Space Complexity: O(D)
*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> vect_out;
        for (int i = left; i <= right; ++i) {
            if (is_self_driving_number(i)) {
                vect_out.push_back(i);
            }
        }
        return vect_out;
    }

    bool is_self_driving_number(const int& num) {
        int tmp_num = num;
        int den = 0;
        while (tmp_num != 0) {
            den = tmp_num % 10;
            if (den == 0 || num % den != 0) {
                return false;
            }
            tmp_num /= 10;
        }
        return true;
    }
};



int main() {
    VectorUtil::print_vector1d(Solution().selfDividingNumbers(1, 22));
    return 0;
}
