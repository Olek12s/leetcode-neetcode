class Solution {
private:
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxLeft = height(root->left);
        int maxRight = height(root->right);

        maxDiameter = max(maxDiameter, maxLeft + maxRight);

        return max(maxLeft, maxRight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        height(root);
        return maxDiameter;
    }
};