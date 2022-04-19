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
    
    int sumEvenGrandparent(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root) ;
        int ans = 0 ;
        
        while(!q.empty())
        {
                TreeNode* temp = q.front() ;
                q.pop() ;
                
                if(temp->val%2==0)
                {
                    if(temp->left!=NULL&&temp->left->left!=NULL)
                        ans+=temp->left->left->val ;
                    if(temp->left!=NULL&&temp->left->right!=NULL)
                        ans+=temp->left->right->val ;
                    if(temp->right!=NULL&&temp->right->left!=NULL)
                        ans+=temp->right->left->val ;
                    if(temp->right!=NULL&&temp->right->right!=NULL)
                        ans+=temp->right->right->val ;
                    }
                    if(temp->left)
                        q.push(temp->left);
                    
                    if(temp->right)
                        q.push(temp->right);
            
        }
        
        return ans ;
    }
    
};