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
    unordered_map<int, int> um;
    int cnt=0;
    void f(TreeNode* root){
        if(root == NULL) return;
        um[root->val]++;
        if(root->left == NULL and root->right == NULL){
            int odd=0;
            for(auto it:um){
                if(it.second%2){
                    odd++;
                }
            }
            if(odd <= 1) cnt++;
        }
        f(root->left);
        f(root->right);
        um[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL) return 0;
        f(root);
        return cnt;
    }
};