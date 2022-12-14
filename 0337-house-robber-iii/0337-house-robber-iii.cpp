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
    unordered_map<TreeNode*, int> um;
    
    int f(TreeNode* root){
        if(root == NULL) return 0;
        
        if(um.count(root)) return um[root];
        
        int with_root = root->val;
        
        if(root->left != NULL) 
            with_root += f(root->left->left) + f(root->left->right);
        
        if(root->right != NULL)
            with_root += f(root->right->left) + f(root->right->right);
        
        int without_root = 0;
        
        if(root->left != NULL) without_root += f(root->left);
        if(root->right != NULL) without_root += f(root->right);
        
        return um[root] = max(with_root, without_root);
    }
    int rob(TreeNode* root) {
        return f(root);
    }
};