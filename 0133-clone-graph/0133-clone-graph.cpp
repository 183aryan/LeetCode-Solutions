/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(mp.find(node) != mp.end()) return mp[node];
        Node* newNode = new Node(node->val);
        
        mp[node] = newNode;
        for(Node* n:node->neighbors){
            if(mp.count(n) == 0) newNode->neighbors.push_back(cloneGraph(n));
            
            else newNode->neighbors.push_back(mp[n]);
        }
        return newNode;
    }
};