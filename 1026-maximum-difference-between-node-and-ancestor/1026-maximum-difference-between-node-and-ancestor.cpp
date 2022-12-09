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
    // in this question we are finding minimum and maximum from every subtree and keep on updating ans with max difference value.
    int f(TreeNode* root, int maxi, int mini){
        if(root == NULL) return abs(maxi-mini);
        
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        
        return max(f(root->left, maxi, mini), f(root->right, maxi, mini));
    }
    int maxAncestorDiff(TreeNode* root) {
        return f(root, root->val, root->val);
    }
};