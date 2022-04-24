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

    // Encodes a tree to a single string.
    void search(TreeNode* root, string& s){
        if(!root){
            s.push_back('#');
            return;
        }
        s += (to_string(root->val));
        s += ",";
        search(root->left,s);
        search(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s = "";
        search(root,s);
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode *decode(string& data){
        if(data.size() == 0) return NULL;
        if(data[0] == '#'){
            data = data.substr(1);
            return NULL;
        }
        int idx = 0;
        string t = "";
        while(data[idx] != ','){
            t += data[idx++];
            // idx++;
        }
        TreeNode *curr = new TreeNode(stoi(t));
        data = data.substr(idx+1);
        curr->left = decode(data);
        curr->right = decode(data);
        return curr;
    }
    TreeNode* deserialize(string data) {
        if(data.size()<1) return NULL;
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));