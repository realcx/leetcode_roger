/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]

Example 1:
Input: "IDID"
Output: [0,4,1,3,2]

Example 2:
Input: "III"
Output: [0,1,2,3]

Example 3:
Input: "DDI"
Output: [3,2,0,1]

Note:
1 <= S.length <= 10000
S only contains characters "I" or "D".
*/

/*
Result:
Runtime: 40 ms, faster than 99.80% of C++ online submissions for DI String Match.
Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for DI String Match.
*/

/*
Analysis:
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        const int len = S.length();
        vector<int> vect_out(len + 1);
        int smallest_value = 0;
        int biggest_value = len;

        for (int i = 0; i < len; i++) {
            if (S[i] == 'I') {
                vect_out[i] = smallest_value;
                smallest_value++;
            } else if (S[i] == 'D') {
                vect_out[i] = biggest_value;
                biggest_value--;
            }
        }
        vect_out[len] = biggest_value;

        return vect_out;
    }
};


int main() {
    Solution obj;
    vector<int> v = obj.diStringMatch("IDID");
    VectorUtil::print_vector1d(v);
    return 0;
}
