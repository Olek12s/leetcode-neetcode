/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) return nullptr;
        if (p->val < root->val && q->val < root->val) 
        { // Both nodes are in the left subtree
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val) 
        { // Both nodes are in the right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
        // We found the split point or one of the nodes matches root
        return root;
    }
};