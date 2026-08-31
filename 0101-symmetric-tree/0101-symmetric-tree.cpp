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

    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root->left,root->right});
        while(!q.empty()){
            auto n= q.front();
            q.pop();
            TreeNode* node1= n.first;
            TreeNode* node2= n.second;
            if(!node1 && !node2)continue;
            if(!node1 || !node2 || (node1->val!=node2->val)){
                return false;
            }
            q.push({node1->left, node2->right});
            q.push({node1->right, node2->left});
        }
        return true;
    }
};