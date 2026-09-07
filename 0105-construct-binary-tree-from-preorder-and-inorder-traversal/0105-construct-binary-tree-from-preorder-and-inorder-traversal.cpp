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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= preorder.size();
        map<int,int>tree;
        for(int i=0;i<n;i++){
            tree[inorder[i]]=i;
        }
        TreeNode* root= build(preorder,0,n-1,inorder,0,n-1,tree);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd ,vector<int>& inorder, int inStart, int inEnd, map<int,int>&tree){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        TreeNode* root= new TreeNode(preorder[preStart]);
        int inRoot= tree[root->val];
        int num_left= inRoot-inStart;
        root->left= build(preorder, preStart+1, preStart + num_left, inorder, inStart, inRoot-1,tree);
        root->right= build(preorder, preStart + num_left+ 1, preEnd, inorder, inRoot + 1, inEnd, tree);
        return root;
    }
};