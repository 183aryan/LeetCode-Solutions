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
    int cnt=0;
    void traverse(TreeNode* root, long long int targetSum){
        if(root == NULL) return;
        
        if(root->val == targetSum) cnt++;
        traverse(root->left, targetSum-root->val);
        traverse(root->right, targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        traverse(root, targetSum); 
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return cnt;
    }
};