//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        if(M != N) return 0;
        
        int i=0;
        int j=0;
        
        while(i<M || j<N){
            while(i<N and S[i] =='#') i++;
            while(j<N and T[j] =='#') j++;
            
            if(S[i] != T[j]) return 0;
            
            if(S[i] == 'A' and i < j) return 0;
            if(S[i] == 'B' and i > j) return 0;
            
            i++;
            j++;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends