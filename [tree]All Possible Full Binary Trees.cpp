/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/tree_util.hpp"

using namespace std;

/* 
Descrition:

*/

/*
Result:

*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    bool allPossibleFBTAssistance(int N, TreeNode* root_ptr,
                                  TreeNode* node_ptr, std::vector<TreeNode*>* node_vect_ptr) {
        if (1 == N) {
            return true;
        }

        for (int i = 1; i < N; i += 2) {
            node_ptr->left = new TreeNode(0);
            node_ptr->right = new TreeNode(0);
            bool left_over = allPossibleFBTAssistance(i, root_ptr, node_ptr->left, node_vect_ptr);
            bool right_over = allPossibleFBTAssistance(N - i - 1, root_ptr, node_ptr->right, node_vect_ptr);
            if (left_over && right_over) {
                node_vect_ptr->push_back(root_ptr);
            }
        }

        return false;
    }

    vector<TreeNode*> allPossibleFBT(int N) {
        std::vector<TreeNode*> node_vect;
        TreeNode* node_ptr = new TreeNode(0);
        node_vect.push_back(node_ptr);
        allPossibleFBTAssistance(N, node_ptr, node_ptr, &node_vect);
        return node_vect;
    }
};


int main() {
    // vector<TreeNode*> v = Solution().allPossibleFBT(3);
    // for (const auto* tree_node : v) {
    //     TreeUtil::print_tree(tree_node);
    // }

    TreeNode* tree_node = NULL;
    std::vector<int> v = {1,2,3,-1,-1,4,5};
    TreeUtil::vector_to_tree(v, tree_node);
    TreeUtil::print_tree(tree_node);
    std::cout << TreeUtil::tree_height(tree_node) << std::endl;
    TreeUtil::print_tree(tree_node);

    // TreeNode* tree_node = new TreeNode(1);
    // tree_node->left = new TreeNode(2);
    // tree_node->right = new TreeNode(3);
    // tree_node->left->left = new TreeNode(4);
    // tree_node->left->left->left = new TreeNode(5);
    // std::cout << TreeUtil::tree_height(tree_node) << std::endl;
    // TreeUtil::print_tree(tree_node);
    return 0;
}
