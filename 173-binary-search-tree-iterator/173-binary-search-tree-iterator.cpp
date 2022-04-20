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
class BSTIterator {
public:
    stack<TreeNode *> s1,s2;
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        s1.push(root);
        inorder(root->right);
    }
    void check(stack<TreeNode *>& s1,stack<TreeNode *>& s2){
        while(s1.empty() == false){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int next() {
       check(s1,s2);
        auto x = s2.top();
        s2.pop();
        return x->val;
    }
    
    bool hasNext() {
        check(s1,s2);
        if(s2.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */