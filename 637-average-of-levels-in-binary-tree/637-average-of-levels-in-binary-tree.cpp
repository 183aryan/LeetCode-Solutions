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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};
        vector<double> v;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            double sum = 0;
            for(int i=0;i<sz;i++){
                auto x = q.front();
                q.pop();
                sum += x->val;
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
            }
            v.push_back(sum/sz);
        }
        return v;
    }
};