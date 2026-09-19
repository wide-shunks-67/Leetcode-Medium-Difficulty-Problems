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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = build(preorder, 0, preorder.size() - 1, n);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int left_idx, int right_idx, int n) {
        if (left_idx > right_idx || right_idx >= n)
            return nullptr;

        int lefti = 0;
        int i = left_idx + 1;

        while (left_idx < right_idx && i <= right_idx &&
               preorder[i] < preorder[left_idx]) {
            i++;
            lefti++;
        }
        TreeNode* root = new TreeNode(preorder[left_idx]);
        root->left = build(preorder, left_idx + 1, left_idx + lefti, n);
        root->right = build(preorder, left_idx + lefti + 1, right_idx, n);
        return root;
    }
};