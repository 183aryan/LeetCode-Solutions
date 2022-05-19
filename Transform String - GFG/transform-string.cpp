// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        unordered_map<char,int> um;
        for(auto x:A) um[x]++;
        for(auto x:B) um[x]--;
        
        for(auto x:um){
            if(x.second != 0) return -1;
        }
        
        int i=A.size()-1,j=B.size()-1;
        int res = 0;
        
        while(i>=0 and j>=0){
            if(A[i] == B[j]){
                i--;
                j--;
            }
            else{
                res++;
                i--;
            }
        }
        return res;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends