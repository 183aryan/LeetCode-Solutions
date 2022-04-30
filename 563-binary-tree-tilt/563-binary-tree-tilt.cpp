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
    int diff = 0;
    int tilt(TreeNode* root){
        if(root == NULL) return 0;
        int ls = tilt(root->left);
        int rs = tilt(root->right);
        diff += abs(ls-rs);
        return ls + rs + root->val;
    }
    int findTilt(TreeNode* root) {
        tilt(root);
        return diff;
    }
};