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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> v;
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.empty() == false){
            int cnt = q.size();
            vector<int> v1;
            for(int i=0;i<cnt;i++){
                auto x = q.front();
                q.pop();
                v1.push_back(x->val);
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
            }
            v.push_back(v1);
        }
        return v;
    }
};