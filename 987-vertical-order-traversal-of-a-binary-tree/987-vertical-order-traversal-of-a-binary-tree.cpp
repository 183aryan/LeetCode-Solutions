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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        if(!root) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            unordered_map<int,vector<int>> row;
            for(int i=q.size() ; i>0 ; i--){
                auto node=q.front().first;
                auto col=q.front().second;
                q.pop();
                row[col].push_back(node->val);
                if(node->left)q.push({node->left,col-1});
                if(node->right)q.push({node->right,col+1});
            }
            for(auto& c:row){
                auto col=c.first;
                auto val=c.second;
                sort(val.begin(),val.end());
                mp[col].insert(mp[col].end(),val.begin(),val.end());
            }
        }
        vector<vector<int>> ans;
        for(auto& i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};