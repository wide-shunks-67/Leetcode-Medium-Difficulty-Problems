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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
       
        queue<pair<TreeNode*,int>>q;

        q.push({root,0});
        int max_len=1;
        while(!q.empty()){
            int n= q.size();
            int start= q.front().second;
            int end= q.back().second;
            max_len= max(max_len,end-start+1);
            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();
                TreeNode* p= node.first;
               int idx= node.second - start;
                
                if(p->left){
                    q.push({p->left,2LL*idx+ 1});
                }
                if(p->right){
                    q.push({p->right,2LL*idx+2});
                }
            }
           
        }
        return max_len;
    }
};