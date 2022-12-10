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
    long long int mod = 1e9+7;
    long long int tot_sum=0;
    long long int maxi = INT_MIN;
    
    long long int traversal(TreeNode* root){
        if(root == NULL) return 0;
        
        long long int curr_sum = traversal(root->left) + traversal(root->right) + root->val;
        maxi = max(maxi, (tot_sum - curr_sum)*curr_sum);
        
        return curr_sum;
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;
        
        inorder(root->left);
        tot_sum += root->val;
        inorder(root->right);
    }
    int maxProduct(TreeNode* root) {
        inorder(root);
        traversal(root);
        return (long long int)maxi%mod;
    }
};