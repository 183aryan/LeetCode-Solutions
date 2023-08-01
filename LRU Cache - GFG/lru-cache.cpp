//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
     class node {
      public:
          int key;
          int val;
          node * next;
          node * prev;
          node(int _key, int _val) {
            key = _key;
            val = _val;
          }
        };

    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    int cap;
    unordered_map < int, node * > m;
    
    
    // add a node
    void addNode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    // delete a node
    void deleteNode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
      }
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
         if(m.find(key) != m.end()){
            node* newNode = m[key];
            int res = newNode->val;
            m.erase(key);
            deleteNode(newNode);
            addNode(newNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here 
        if(m.find(key) != m.end()){
            node* exist = m[key];
            m.erase(key);
            deleteNode(exist);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends