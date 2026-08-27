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
void lot(TreeNode* root, vector<vector<int>>&ans){
    if(root==nullptr)return;
   
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
         vector<int>levels;
        for(int i=0;i<n;i++){
            TreeNode* front=q.front();
            levels.push_back(front->val);
            if(front->left!=nullptr){
                q.push(front->left);
            }
            if(front->right!=nullptr){
                q.push(front->right);
            }
            q.pop();
        }
        ans.push_back(levels);
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        lot(root,ans);
        return ans;
    }
};