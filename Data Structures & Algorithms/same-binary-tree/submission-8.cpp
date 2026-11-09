
class Solution {
public:

    vector<TreeNode*> dfs(TreeNode* root) {
        vector<TreeNode*> res;

        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            res.push_back(node);

            if (node != nullptr) {
                stack.push(node->left);
                stack.push(node->right);
            }
        }
        return res;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> nodeP = dfs(p);
        vector<TreeNode*> nodeQ = dfs(q);

        if (nodeP.size() != nodeQ.size()) return false;

        for (int i = 0; i < nodeP.size(); i++) {
            if (nodeP[i] == nullptr && nodeQ[i] == nullptr) continue;
            if (nodeP[i] == nullptr || nodeQ[i] == nullptr) return false;
            if (nodeP[i]->val != nodeQ[i]->val) return false;
        }
        return true;
    }
};