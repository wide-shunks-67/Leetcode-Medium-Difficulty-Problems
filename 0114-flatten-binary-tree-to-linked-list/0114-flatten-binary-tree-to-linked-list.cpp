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
void pre(TreeNode* root, vector<TreeNode*>&node){
    if(root==nullptr)return;
    node.push_back(root);
    pre(root->left,node);
    pre(root->right,node);
}
    void flatten(TreeNode* root) {
        if(root==nullptr)return;
        vector<TreeNode*>nodes;
        pre(root,nodes);
        for(int i=0;i<nodes.size()-1;i++){
            nodes[i]->left=NULL;
            nodes[i]->right= nodes[i+1];
        }
    }
};