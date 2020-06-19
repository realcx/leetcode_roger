#include <queue>
#include <vector>
#include "vector_util.hpp"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class TreeUtil {
public:
    TreeUtil() = default;
    ~TreeUtil() = default;

    // chnage vector to tree, -1 means NULL
    static void vector_to_tree(const std::vector<int>& vect, TreeNode* tree) {
        if (vect.size() < 1) {
            tree = NULL;
            std::cout << "ERROR: wrong vector size" << std::endl;
            return;
        }

        tree = new TreeNode(vect[0]);
        std::vector<TreeNode*>* v_tmp = new std::vector<TreeNode*>();
        v_tmp->push_back(std::move(tree));

        int i = 1;
        int j = 0;
        while (i < vect.size() && j < v_tmp->size()) {
            auto*& curr_tree = (*v_tmp)[j];

            if (vect[i] >= 0) {
                curr_tree->left = new TreeNode(vect[i++]);
                v_tmp->push_back(std::move(curr_tree->left));
            } else {
                i++;
            }

            if (vect[i] >= 0) {
                curr_tree->right = new TreeNode(vect[i++]);
                v_tmp->push_back(std::move(curr_tree->right));
            } else {
                i++;
            }

            j++;
            std::cout << "i:" << i << ", j:" << j << std::endl;
            print_tree(tree);
        }

        *tree = *(v_tmp->front());
        print_tree(tree);
        delete v_tmp;
        print_tree(tree);
    }

    // change tree to vector, NULL means -1
    static void tree_to_vector(const TreeNode* const tree, std::vector<int>* vect) {
        if (tree == NULL) {
            std::cout << "ERROR: wrong tree size" << std::endl;
            return;
        }

        vect->clear();
        vect->push_back(tree->val);
        std::queue<const TreeNode* const> q;
        q.push(tree);

        while (!q.empty()) {
            auto* curr_tree = q.front();

            if (curr_tree->left == NULL) {
                vect->push_back(-1);
            } else {
                vect->push_back(curr_tree->left->val);
                q.push(curr_tree->left);
            }

            if (curr_tree->right == NULL) {
                vect->push_back(-1);
            } else {
                vect->push_back(curr_tree->right->val);
                q.push(curr_tree->right);
            }

            q.pop();
        }
    }

    // calculate tree hight
    static int tree_height(const TreeNode* const tree) {
        if (tree == NULL) {
            return 0;
        }

        int height = std::max(tree_height(tree->left), tree_height(tree->right)) + 1;
        return height;
    }

    // print tree
    static void print_tree(const TreeNode* const tree) {
        std::vector<int> v;
        tree_to_vector(tree, &v);
        VectorUtil::print_vector1d(v);
    }
};
