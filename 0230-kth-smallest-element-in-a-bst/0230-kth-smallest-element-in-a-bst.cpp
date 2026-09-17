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
int result=-1;
bool found=false;
void inorder(TreeNode* root,int &cnt, int &k){
    if(!root||found)return ;
   
    if(root->left){
        inorder(root->left,cnt,k);
    }
    cnt++;
    if(cnt==k){
        result= root->val;
        found=true;
        return ;
    }

    if(root->right){
        inorder(root->right,cnt,k);
    }
}
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return-1;
       int cnt=0;
       found=false;
        inorder(root,cnt,k);
        return result;
    }
};