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
    void inorder(TreeNode* root, vector<int>& temp){
        if(root != NULL){
           inorder(root->left,temp);
           temp.push_back(root->val);
           inorder(root->right,temp);
        }    
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL and root2 == NULL) return {};
        
        vector<int> v1,v2;

        if(root1 != NULL) inorder(root1,v1);
        if(root2 != NULL) inorder(root2,v2);
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        vector<int> v(v1.size() + v2.size());
        merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
        
        return v;
    }
};