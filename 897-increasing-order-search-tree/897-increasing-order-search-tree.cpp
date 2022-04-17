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
    void inorder(TreeNode* root,TreeNode* &curr){
        if(root == NULL) return;
        inorder(root->left,curr);
        curr->right = new TreeNode(root->val);
        curr = curr->right;
        inorder(root->right,curr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(-1);
        TreeNode* curr = res;
        inorder(root,curr);
        return res->right;
    }
};