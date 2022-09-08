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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        v.clear();
        stack<TreeNode*> st;
        // st.push(root);
        while(root != NULL || st.empty() == false){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }
};