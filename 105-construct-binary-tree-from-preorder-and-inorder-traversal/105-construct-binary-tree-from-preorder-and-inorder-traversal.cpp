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
    unordered_map<int,int> m;
    int idx = 0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int lo,int hi){
        if(lo > hi) return NULL;
        TreeNode* res = new TreeNode(preorder[idx]);
        idx++;
        if(lo == hi) return res;
        int mid = m[res->val];
        res->left = solve(preorder,inorder,lo,mid-1);
        res->right = solve(preorder,inorder,mid+1,hi);
        return res;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() != preorder.size()) return NULL;
        for(int i=0;i<inorder.size();i++) m[inorder[i]] = i;
        int n = inorder.size();
        TreeNode* x = solve(preorder,inorder,0,n-1);
        return x;
    }
};