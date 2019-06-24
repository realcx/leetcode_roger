/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
We are given an array A of N lowercase letter strings, all of the same length.
Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.
For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, 
then the final array after deletions is ["bef", "vyz"], and the remaining columns of A are 
["b","v"], ["e","y"], and ["f","z"].  (Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]].)
Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A 
is in non-decreasing sorted order.
Return the minimum possible value of D.length.

Example 1:
Input: ["cba","daf","ghi"]
Output: 1
Explanation: 
After choosing D = {1}, each column ["c","d","g"] and ["a","f","i"] are in non-decreasing sorted order.
If we chose D = {}, then a column ["b","a","h"] would not be in non-decreasing sorted order.

Example 2:
Input: ["a","b"]
Output: 0
Explanation: D = {}

Example 3:
Input: ["zyx","wvu","tsr"]
Output: 3
Explanation: D = {0, 1, 2}
 
Note:
1 <= A.length <= 100
1 <= A[i].length <= 1000
*/

/*
Result:
Runtime: 60 ms, faster than 80.59% of C++ online submissions for Delete Columns to Make Sorted.
Memory Usage: 13 MB, less than 48.05% of C++ online submissions for Delete Columns to Make Sorted.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        const int size = A.size();
        const int length = A[0].size();
        int count = 0;
        for (int j = 0; j < length; j++) {
            for (int i = 1; i < size; i++) {
                if (A[i][j] < A[i - 1][j]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};


int main() {
    vector<string> v1 = {"cba","daf","ghi"};
    cout << Solution().minDeletionSize(v1) << endl;
    vector<string> v2 = {"a","b"};
    cout << Solution().minDeletionSize(v2) << endl;
    vector<string> v3 = {"zyx","wvu","tsr"};
    cout << Solution().minDeletionSize(v3) << endl;
    return 0;
}
