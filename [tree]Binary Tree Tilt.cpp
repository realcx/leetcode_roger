/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "common/tree_util.h"

using namespace std;

/* 
Descrition:
Given a binary tree, return the tilt of the whole tree.
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree
node values and the sum of all right subtree node values. Null node has tilt 0.
The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1

Note:
The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.
*/

/*
Result:
Runtime: 12 ms, faster than 99.40% of C++ online submissions for Binary Tree Tilt.
Memory Usage: 21.5 MB, less than 99.80% of C++ online submissions for Binary Tree Tilt.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int tilt_sum = 0;
    int findTilt(TreeNode* root) {
        tilt(root);
        return tilt_sum;
    }

    int tilt(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = tilt(root->left);
        int right = tilt(root->right);
        tilt_sum += abs(left - right);
        return left + right + root->val;
    }
};


int main() {

    return 0;
}
