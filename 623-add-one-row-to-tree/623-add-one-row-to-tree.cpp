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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        bool once = false;
        while(q.size() != false){
            int n = q.size();
            while(n--){
                auto x = q.front();
                if(level == depth-1){
                        TreeNode* node = new TreeNode(val);
                        if(x->left) node->left = x->left;
                        // cout << x->left->val << " " << node->val << endl;
                        x->left = node;
                        // cout << x->left->val << " " << node->val << endl;
                        TreeNode* node1 = new TreeNode(val);
                        if(x->right) node1->right = x->right;
                        // cout << x->right->val << " " << node->val << endl;
                        x->right = node1;
                        // cout << x->right->val << " " << node->val << endl;
                        once = true;
                }
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
                q.pop();
            }
            level++;
            if(once == true) break;
        }
        return root;
    }
};