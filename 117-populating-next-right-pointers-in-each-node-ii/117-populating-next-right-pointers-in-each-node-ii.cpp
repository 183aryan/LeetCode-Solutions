/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            Node* prev = NULL;
            for(int i=0;i<cnt;i++){
                Node* x = q.front();
                q.pop();
                x->next = prev;
                prev = x;
                if(x->right != NULL) q.push(x->right);
                if(x->left != NULL) q.push(x->left);
            }
        }
        return root;
    }
};