/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void get(TreeNode* root, int &maxi, int depth){
    if(root==nullptr)return;
    depth++;
    maxi= max(maxi,depth);
    get(root->left,maxi,depth);
    get(root->right,maxi,depth);
}
    int maxDepth(TreeNode* root) {
        int maxi=0;
        get(root, maxi, 0);
        return maxi;
    }
};