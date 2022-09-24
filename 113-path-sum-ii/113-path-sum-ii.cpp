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
    void traverse(TreeNode* root, vector<vector<int>>& v, vector<int>& ans, int targetSum){
        if(root == NULL) return;
        ans.push_back(root->val);
        targetSum -= root->val;
        if(root->left == NULL and root->right == NULL){
            if(targetSum == 0) v.push_back(ans);
        }
        traverse(root->left, v, ans, targetSum);
        traverse(root->right, v, ans, targetSum);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> ans;
        if(root == NULL) return {};
        traverse(root, v, ans, targetSum);
        
        return v;
    }
};