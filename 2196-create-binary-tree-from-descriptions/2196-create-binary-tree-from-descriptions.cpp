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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> um;
        unordered_set<int> s;
        TreeNode* head;
        
        for(auto it:descriptions){
            int pt = it[0];
            int cd = it[1];
            int to_place = it[2];
            
            TreeNode* parent,
                    * child;
            
            if(um.count(pt)){
                parent = um[pt];
            }
            else{
                parent = new TreeNode(pt);
                um[pt] = parent;
            }
            
            if(um.count(cd)){
                child = um[cd];
            }
            else{
                child = new TreeNode(cd);
                um[cd] = child;
            }
            
            if(to_place){
                parent->left = child;
            }
            else parent->right = child;
        }
        
        for(auto it:descriptions){
            s.insert(it[1]); //child
        }
        
        for(auto it:descriptions){
            if(s.find(it[0]) == s.end()) head = um[it[0]];
        }
        
        return head;
    }
};