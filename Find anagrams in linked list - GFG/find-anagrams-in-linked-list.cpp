//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*> v;
        unordered_map<char, int> um1, um2;
        
        for(auto it:s) um1[it]++;
        
        int c1 = um1.size();
        
        Node* lt = head,
            * rt = head;
        
        int c2 = 0;    
        while(rt != NULL){
            um2[rt->data]++;
            
            if(um1[rt->data] == um2[rt->data]) c2++;
            
            while(um2[rt->data] > um1[rt->data]){
                if(um2[lt->data] == um1[lt->data]) c2--;
                um2[lt->data]--;
                lt = lt->next;
            }
            
            if(c1 == c2){
                v.push_back(lt);
                Node* temp = rt->next;
                rt->next = NULL;
                lt = temp, rt = temp;
                um2.clear();
                c2 = 0;
            }
            else rt = rt->next;
        }
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends