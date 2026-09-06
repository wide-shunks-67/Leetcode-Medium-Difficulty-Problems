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
TreeNode* make_parent(TreeNode* root, int start, unordered_map<TreeNode*,TreeNode*>&parent){
    TreeNode* target= nullptr;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        for(int i=0;i<n;i++){
            TreeNode* front= q.front();
            q.pop();
            if(front->val==start){
                target= front;
            }
            if(front->left){
                parent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                parent[front->right]=front;
                q.push(front->right);
            }
        }
    }
    return target;
}

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>visited;
        TreeNode* tar= make_parent(root,start,parent);
        int time=-1;
        queue<TreeNode*>q;
        q.push(tar);
        visited[tar]=true;
        while(!q.empty()){
            int n=q.size();
            time++;
            for(int i=0;i<n;i++){
                TreeNode* front= q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(parent[front] && !visited[parent[front]]){
                    q.push(parent[front]);
                    visited[parent[front]]=true;
                }
            }
        }
        return time;
    }
};