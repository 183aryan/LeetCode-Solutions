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
    TreeNode* insuc(TreeNode* root){
        TreeNode* x = root->right;
        while(x->left) x = x->left;
        return x;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        bool flag = 0;
        if(root == NULL) return NULL;
        if(root->val > key) root->left = deleteNode(root->left,key);
        else if(root->val < key) root->right = deleteNode(root->right,key);
        else{
            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp; flag = 1;
            }
            else if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp; flag = 1;
            }
            else{
                TreeNode* temp = insuc(root);
                swap(root->val,temp->val);
                root->right = deleteNode(root->right,key); flag = 1;
            }
        }        
        if(flag) return root;
        return root;
    }
};