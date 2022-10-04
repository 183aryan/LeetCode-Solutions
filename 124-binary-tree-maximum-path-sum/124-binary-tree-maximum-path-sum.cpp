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
    int maxi = INT_MIN;
    int preorder(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = max(0, preorder(root->left));
        int right = max(0, preorder(root->right));
        
        maxi = max(maxi, left+right+root->val);
        
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        preorder(root);
        return maxi;
    }
};