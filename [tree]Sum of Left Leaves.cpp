/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/tree_util.h"

using namespace std;

/* 
Descrition:
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.4 MB, less than 77.73% of C++ online submissions for Sum of Left Leaves.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL) {
            return sumOfLeftLeaves(root->right);
        } else if (root->left->left == NULL && root->left->right == NULL) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << Solution().sumOfLeftLeaves(root) << endl;
    return 0;
}
