/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Let's call an array A a mountain if the following properties hold:
A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:
Input: [0,1,0]
Output: 1

Example 2:
Input: [0,2,1,0]
Output: 1
*/

/*
Result:
Runtime: 12 ms, faster than 97.30% of C++ online submissions for Peak Index in a Mountain Array.
Memory Usage: 9.3 MB, less than 82.69% of C++ online submissions for Peak Index in a Mountain Array.

*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        const int size = A.size();
        int a  = 0;
        int b = size - 1;
        int i = (a + b) / 2;
        while (a != b) {
            if (A[i] > A[i - 1] && A[i] < A[i + 1]) {
                a = i;
            } else if (A[i] < A[i - 1] && A[i] > A[i + 1]) {
                b = i;
            } else {
                a = i;
                b = i;
            }
            i = (a + b) / 2;
        }
        return i;
    }
};


int main() {
    vector<int> v1 = {0, 1, 0};
    cout << Solution().peakIndexInMountainArray(v1) << endl;
    vector<int> v2 = {0, 2, 1, 0};
    cout << Solution().peakIndexInMountainArray(v2) << endl;
    return 0;
}
