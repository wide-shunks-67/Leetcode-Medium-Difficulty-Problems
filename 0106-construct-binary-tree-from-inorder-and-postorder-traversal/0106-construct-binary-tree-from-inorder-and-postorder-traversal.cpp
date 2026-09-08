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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size();
        unordered_map<int,int>tree;
        for(int i=0;i<n;i++){
            tree[inorder[i]]=i;
        }
        TreeNode* root= build(inorder,0,n-1,postorder,0,n-1,tree);
        return root;
    }
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int>&tree){
        if(postStart>postEnd || inStart>inEnd)return NULL;
        TreeNode* root= new TreeNode(postorder[postEnd]);
        int inRoot= tree[root->val];
        int num_left= inRoot-inStart;
        root->left= build(inorder,inStart, inRoot-1, postorder, postStart, postStart+num_left -1,tree);
        root->right= build(inorder, inRoot+1, inEnd, postorder, postStart+num_left, postEnd-1, tree);
        return root;
    }
};