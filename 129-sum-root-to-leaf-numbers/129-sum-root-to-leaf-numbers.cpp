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
    int preorder(TreeNode* root, int sum){
        if(root == NULL) return 0;
        sum = sum*10 + root->val;
        if(root->left == NULL and root->right == NULL) return sum;
        
        return preorder(root->left, sum) + preorder(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        return preorder(root,0);
    }
};