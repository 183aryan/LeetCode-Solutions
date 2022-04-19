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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int sum;
        while(q.empty() == false){
            int cnt = q.size();
            sum = 0;
            for(int i=0;i<cnt;i++){
                TreeNode* x = q.front();
                q.pop();
                sum += x->val;
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
            }
        }
        return sum;
    }
};