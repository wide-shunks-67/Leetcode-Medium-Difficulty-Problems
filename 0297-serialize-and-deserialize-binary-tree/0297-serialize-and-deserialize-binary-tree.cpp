/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void build(TreeNode* root, string& s) {
        if (root == nullptr){
            s+="N,";
            return;
        }
        s += to_string(root->val) + ',';
        build(root->left, s);
        build(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        build(root, s);
        return s;
    }
    //helper function for desearlization

    TreeNode* decode(stringstream& ss) {
        string val;
        if (!getline(ss, val, ',')) {
            return nullptr;
        }

        if (val == "N") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        root->left = decode(ss);
        root->right = decode(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));