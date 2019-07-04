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

    template<typename T>
    static void vector_to_tree(const vector<T>& v, TreeNode* tree) {
    }

    template<typename T>
    static void print_tree(const TreeNode* tree) {
    }
};
