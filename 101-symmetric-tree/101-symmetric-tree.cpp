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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() and !q2.empty()){
            TreeNode* x;
            TreeNode* y;
            x = q1.front();q1.pop();
            y = q2.front();q2.pop();
            if(x == NULL and y == NULL) continue;;
            if(x == NULL || y == NULL) return false;
            if(x->val != y ->val) return false;
            q1.push(x->left);            
            q1.push(x->right);
            q2.push(y->right);
            q2.push(y->left);
        }
        return true;
    }
};