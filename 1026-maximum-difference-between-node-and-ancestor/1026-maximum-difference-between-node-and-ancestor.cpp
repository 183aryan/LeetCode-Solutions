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
    int ans = INT_MIN;
    int mn,mx;
    void find(TreeNode* root, int mn, int mx){
        if(root == NULL) return;
        ans = max({ans,root->val-mn,mx-root->val});
        mn = min(mn,root->val);
        mx = max(mx,root->val);
        find(root->right,mn,mx);
        find(root->left,mn,mx);
        // find(root->right,mn,mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        mn = root->val;
        mx = root->val;
        find(root,mn,mx);
        return ans;
    }
};