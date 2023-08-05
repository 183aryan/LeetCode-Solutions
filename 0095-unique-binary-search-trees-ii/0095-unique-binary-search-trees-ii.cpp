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
    vector<TreeNode*> f(int lo, int hi){
        vector<TreeNode*> v;
        if(lo > hi){
            v.push_back(NULL);
            return v;
        }
        for(int i=lo;i<=hi;i++){
            vector<TreeNode*> leftTree = f(lo, i-1);
            vector<TreeNode*> rightTree = f(i+1, hi);
            
            for(auto &j:leftTree){
                for(auto &k:rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = j;
                    root->right = k;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return f(1, n);
    }
};