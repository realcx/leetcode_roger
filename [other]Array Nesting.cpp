/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <set>
#include <cassert>
#include <vector>
#include <algorithm>

#include "common/vector_util.hpp"

using namespace std;

/* 
Descrition:
A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest
length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next
element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before
a duplicate element occurs in S.


Example 1:
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}


Note:
N is an integer within the range [1, 20,000].
The elements of A are all distinct.
Each element of A is an integer within the range [0, N-1].
*/

/*
Result:
Runtime: 64 ms, faster than 10.97% of C++ online submissions for Array Nesting.
Memory Usage: 14 MB, less than 27.27% of C++ online submissions for Array Nesting.
*/

/*
Analysis:
Time Complexity: O()
Space Complexity: O(n)
*/


class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_counter = 1;
        std::set<int> s;

        for (size_t i = 0; i < nums.size(); i++) {
            int first_value = nums[i];
            int j = nums[i];
            int counter = 1;
            s.insert(i);

            if (s.find(j) != s.end()) {
                continue;
            }

            while (nums[j] != first_value) {
                s.insert(j);
                j = nums[j];
                counter++;
            }

            if (counter >= max_counter) {
                max_counter = counter;
            }
        }

        return max_counter;
    }
};


int main() {
    std::vector<int> v = {5,4,0,3,1,6,2};
    VectorUtil::print_vector1d(v);
    std::cout << Solution().arrayNesting(v) << std::endl;
    return 0;
}
