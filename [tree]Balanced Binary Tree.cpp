/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "common/tree_util.hpp"

using namespace std;

/* 
Descrition:
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/

/*
Result:
Runtime: 8 ms, faster than 98.11% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 17.2 MB, less than 80.21% of C++ online submissions for Balanced Binary Tree.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        depth(root);
        return is_balanced_;
    }

    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (abs(left_depth - right_depth) > 1) {
            is_balanced_ = false;
        }
        return 1 + max(left_depth, right_depth);
    }

private:
    bool is_balanced_ = true;
};


int main() {

    return 0;
}
