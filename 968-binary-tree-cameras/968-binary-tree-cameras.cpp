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
    int cnt = 0;
    int no_cam = 0;
    int has_cam = 2;
    int not_needed = 1;
    
    int postorder(TreeNode* root){
        if(root == NULL) return not_needed;
        
        int left = postorder(root->left);
        int right = postorder(root->right);
        
        if(left == no_cam || right == no_cam) {
            cnt++;
            return has_cam;
        }
        else if(left == has_cam || right == has_cam) return not_needed;
        else return no_cam;
    }
    int minCameraCover(TreeNode* root) {
        if(postorder(root) == no_cam) cnt++;
        return cnt;
    }
};