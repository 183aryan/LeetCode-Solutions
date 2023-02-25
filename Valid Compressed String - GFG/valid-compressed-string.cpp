//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i=0, j=0;
        while(i < S.size() and j < T.size()){
            if(isdigit(T[j])){
                // int x = T[j] - '0';
                int x=0;
                int cnt=0;
                while(j < T.size() and isdigit(T[j])){ x = x*10 + (T[j] - '0'); j++;}
                // while(i < S.size() and x--){
                //     i++;
                //     cnt++;
                // }
                // if(x != 0) return 0;
                i += x;
            }
            else if(S[i] == T[j]){
                i++;
                j++;
            }
            else return 0;
        }
        return (i == S.size() and j == T.size());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends