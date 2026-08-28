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
int check(TreeNode*root, int& maxi){
    if(root==nullptr)return 0;
    int left_sum=max(0,check(root->left,maxi));
    int right_sum= max(0,check(root->right,maxi));
    maxi= max(maxi, left_sum+right_sum+root->val);
    return max(left_sum,right_sum) + root->val;
}
    int maxPathSum(TreeNode* root) {
        int path_sum=INT_MIN;
        check(root,path_sum);
        return path_sum;
    }
};