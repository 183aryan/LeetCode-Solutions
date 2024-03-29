//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        // code here
        bool flag = false;
        
        for(int i=2;i<=32;i++){
            int temp = n;
            int cnt=0;
            while(temp){
                temp /= i;
                cnt++;
            }
            if(cnt == m){
                flag = true;
                break;
            }
        }
        if(flag) return "Yes";
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends