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
        vector<vector<int>> v;
        
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(q.empty() == false){
            int sz = q.size();
            vector<int> v1;
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                v1.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            if(flag == false){
                flag = true;
                v.push_back(v1);
            }
            else{
                flag = false;
                reverse(v1.begin(), v1.end());
                v.push_back(v1);
            }
        }
        return v;
    }
};