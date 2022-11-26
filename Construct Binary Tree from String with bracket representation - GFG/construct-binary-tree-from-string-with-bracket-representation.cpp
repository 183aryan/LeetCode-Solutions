//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        stack<Node*> st;
        
        for(int i=0;i<str.size();i++){
            if(str[i] == '(') continue;
            else if(isdigit(str[i])){
                string t = "";
                while(i<str.size() and isdigit(str[i])){
                    t += str[i];
                    i++;
                }
                Node* node = new Node(stoi(t));
                st.push(node);
                i--;
            }
            else{
                Node* child = st.top();
                st.pop();
                Node* parent = st.top();
                // st.pop();
                if(parent->left == NULL) parent->left = child;
                else if(parent->right == NULL) parent->right = child;
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends