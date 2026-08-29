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
void solve(vector<vector<int>>&ans, TreeNode* root){
    if(root==nullptr)return ;
    queue<TreeNode*>q;
    q.push(root);
    int counter=0;
    while(!q.empty()){
        vector<int>levels;
         
         int n= q.size();
         for(int i=0;i<n;i++){
            TreeNode* node= q.front();
            q.pop();
            levels.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
         }
         if(counter==1){
            reverse(levels.begin(),levels.end());
            ans.push_back(levels);
            counter=0;
         }
         else{
            ans.push_back(levels);
            counter=1;
         }
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>bfs;
         solve(bfs,root);
         return bfs;
    }
};