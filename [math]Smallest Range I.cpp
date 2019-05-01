/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
After this process, we have some array B.
Return the smallest possible difference between the maximum value of B and the minimum value of B.

Example 1:
Input: A = [1], K = 0
Output: 0
Explanation: B = [1]

Example 2:
Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]

Example 3:
Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]

Note:
1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/

/*
Result:
Runtime: 20 ms, faster than 96.67% of C++ online submissions for Smallest Range I.
Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Smallest Range I.
*/

/*
Analysis:
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min_num = A[0];
        int max_num = A[0];
        for (const int& num : A) {
            if (num > max_num)
                max_num = num;
            if (num < min_num)
                min_num = num;
        }
        return std::max(0, max_num - min_num - 2 * K);
    }
};


int main() {
    std::vector<int> v1 = {1, 3, 6};
    cout << Solution().smallestRangeI(v1, 3) << endl;
    std::vector<int> v2 = {0, 10};
    cout << Solution().smallestRangeI(v2, 2) << endl;
    return 0;
}

