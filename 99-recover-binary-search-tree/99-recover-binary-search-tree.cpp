/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode *prev = NULL;
    TreeNode *first = NULL;
    TreeNode *second = NULL;

    void inorder(TreeNode *root)
    {
        if (root == NULL) return;
        inorder(root->left);
        if (prev != NULL and prev->val > root->val)
        {
        	// checking whether inorder is correct or not.....
            if (first == NULL)
            {
                first = prev;	// mark first juction.....
            }
            second = root;	// second point.....
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(first->val, second->val);
    }
};