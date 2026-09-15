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
TreeNode* helper(TreeNode* root, int key){
    if(root->left==NULL){
        return root->right;
    }
    if(root->right==NULL){
        return root->left;
    }
    TreeNode* rightchild= root->right;
    TreeNode* lastright= find(root->left);
    lastright->right= rightchild;
    return root->left;
}
TreeNode *find( TreeNode* root){
    while(root->right){
        root=root->right;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val==key){
            return helper(root,key);
        }
        TreeNode* dummy= root;
        while(root){
            if(root->val > key){
                if(root->left && root->left->val==key){
                    root->left =  helper(root->left,key);
                    break;
                }
                root=root->left;
            }
            else{
                if(root->right && root->right->val==key){
                    root->right= helper(root->right, key);
                    break;
                }
                root = root->right;
            }
        }
        return dummy;
    }
};