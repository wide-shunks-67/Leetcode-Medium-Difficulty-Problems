/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
    if(root==nullptr)return;
    queue<TreeNode*>q;

    q.push(root);
    while(!q.empty()){
        int n= q.size();
        for(int i=0;i<n;i++){
            TreeNode* node= q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]= node;
                q.push(node->right);
            }
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        mark_parents(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int level=0;
        while(!q.empty()){
            int n= q.size();
            if(level++==k)break;
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
                if(parent[front]&& !visited[parent[front]]){
                    q.push(parent[front]);
                    visited[parent[front]]=true;
                }
            }
        }
        vector<int>dis;
        while(!q.empty()){
            TreeNode* front= q.front();q.pop();
            dis.push_back(front->val);
        }
        return dis;
    }
};