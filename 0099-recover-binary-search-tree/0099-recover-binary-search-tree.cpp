/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* prev = NULL;
    TreeNode* second = NULL;
    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        helper(root);
        if (first && second) {
            swap(first->val,second->val);
        }
    }
    void helper(TreeNode* root) {
        if (!root)
            return;
        helper(root->left);
        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;
        helper(root->right);
    }
};