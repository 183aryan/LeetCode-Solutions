/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        vector<int> v;
        queue<Node *> q;
        q.push(root);
        while(q.empty()==false){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                v.push_back(q.front()->val);
                auto x = q.front();;
                q.pop();
                for(auto it:x->children) q.push(it);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};