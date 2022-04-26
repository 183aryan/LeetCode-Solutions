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
class FindElements {
public:
    TreeNode* node;
    FindElements(TreeNode* root) {
        node = root;
        node->val = 0;
        search(node);
    }
    void search(TreeNode* node){
        if(node == NULL) return;
        int x = node->val;
        if(node->left != NULL) node->left->val = 2*x + 1;
        if(node->right != NULL) node->right->val = 2*x + 2;
        
        search(node->left);
        search(node->right);
    }
    bool find(int target) {
        return find(node,target);
    }
    bool find(TreeNode* node,int target){
        if(node == NULL) return false;
        if(node->val == target) return true;
        
        return find(node->left,target) || find(node->right,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */