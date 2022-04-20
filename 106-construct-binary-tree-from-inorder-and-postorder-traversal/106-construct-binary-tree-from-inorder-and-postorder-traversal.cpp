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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int lo,int hi,int& idx){
        if(lo > hi) return NULL;
        TreeNode* res = new TreeNode(postorder[idx]);
        idx--;
        if(lo == hi) return res;
        int mid = m[res->val];
        res->right = solve(inorder,postorder,mid+1,hi,idx);  
        res->left = solve(inorder,postorder,lo,mid-1,idx);
        
        return res;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        m.clear();
        int idx = postorder.size()-1;
        for(int i=0;i<inorder.size();i++) m[inorder[i]] = i;
        int n = inorder.size();
        TreeNode* x = solve(inorder,postorder,0,n-1,idx);
        return x;
    }
};