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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        stack<int> s;
        vector<int> v;
        while(!q.empty()){
            int cnt = q.size();
            v.resize(cnt);
            v.clear();
            for(int i=0;i<cnt;i++){
                TreeNode* x = q.front();
                q.pop();
                if(flag)
                v.push_back(x->val);
                else{
                    s.push(x->val);
                }
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
            }
            if(flag == false){
                while(s.empty() == false){ v.push_back(s.top());s.pop();}
            }
            flag = !flag;
            res.push_back(v);
        }
        return res;
    }
};