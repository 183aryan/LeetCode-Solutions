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
    unordered_map<string, int> um;
    vector<TreeNode*> v;
    
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        
        // string s = serialize(root->left) + "," + serialize(root->right) + "," + to_string(root->val);
        // Or
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        string s = left + "," + right + "," + to_string(root->val);
        
        um[s]++;
        if(um[s] == 2) v.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return v;
    }
};