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
    // stack<TreeNode *> s1,s2;  // when you will make all stack based functions uncommented and vector based commented then will able to get answer(accepted) with use 2 stack method.
    vector<int> v;    // vector method
    int i=0;
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);                   
        // s1.push(root);                  // stack
        v.push_back(root->val);            // vector
        inorder(root->right);
    }
    // void check(stack<TreeNode *>& s1,stack<TreeNode *>& s2){
    //     while(s1.empty() == false){
    //         s2.push(s1.top());
    //         s1.pop();
    //     }                               // check function is used for 2 stack method.
    // }
    int next() {
       // check(s1,s2);
        // auto x = s2.top();
        // s2.pop();                       // 2 stack method
        // return x->val;
        int x = v[i];
        i++;                               // vector method
        return x;
    }
    
    bool hasNext() {
        // check(s1,s2);
        // if(s2.empty()) return false;   // 2 stack method
        // return true;
        if(i<v.size()) return true;
        return false;                     // vector method
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */