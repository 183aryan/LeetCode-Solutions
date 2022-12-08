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
    void leaf(TreeNode* root, vector<int>& v){
        if(root == NULL) return;
        
        leaf(root->left, v);
        if(root->left == NULL and root->right == NULL) v.push_back(root->val);
        leaf(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        leaf(root1, v1);
        leaf(root2, v2);
        
        for(int i=0;i<max(v1.size(), v2.size());i++){
            cout << v1[i] << " " << v2[i] << endl;
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};