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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(q.empty() == false){
            int cnt = q.size();
            for(int i=0;i<cnt;i++){
                TreeNode* x = q.front();
                q.pop();
                if(i == cnt-1){
                    v.push_back(x->val);
                }
                if(x->left!=NULL) q.push(x->left);
                if(x->right!=NULL) q.push(x->right);
            }
        }
        return v;
    }
};