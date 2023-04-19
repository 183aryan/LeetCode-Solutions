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
    void dfs(TreeNode* root, bool left, int steps){
        if(root == NULL) return;
        maxi = max(maxi, steps);
        cout << "maxi = " << maxi << endl;
        if(left){
            cout << "hi" << endl;
            dfs(root->left, false, steps+1);
            dfs(root->right, true, 1);
        }
        else{
            cout << "hello" << endl;
            dfs(root->right, true, steps+1);
            dfs(root->left, false, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL) return -1;
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxi;
    }
};