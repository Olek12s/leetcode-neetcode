
class Solution {
public:
    bool balanced = true;


    vector<TreeNode*> dfs(TreeNode* root) {
        vector<TreeNode*> res;
        if (root == nullptr) return res;

        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            res.push_back(node);

            if (node->right != nullptr) stack.push(node->right);
            if (node->left != nullptr) stack.push(node->left);
        }
        return res;
    }

    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;


        vector<TreeNode*> nodes = dfs(root);

        for (TreeNode* node : nodes) {
            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);

            if (abs(leftHeight - rightHeight) > 1) {
                balanced = false;
                break; 
            }
        }
        return balanced;
    }
};
