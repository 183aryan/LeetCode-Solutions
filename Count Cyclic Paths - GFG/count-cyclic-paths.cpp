//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    const int mod = 1e9+7;
    
    // long long int f(int n, char ch){
    //     if(n == 0) return ch == 'o'?1:0;
        
    //     if(ch == 'o') return f(n-1, 'a') + f(n-1, 'b') + f(n-1, 'c');
    //     else if(ch == 'a') return f(n-1, 'b') + f(n-1, 'c') + f(n-1, 'o');
    //     else if(ch == 'b') return f(n-1, 'a') + f(n-1, 'c') + f(n-1, 'o');
    //     return f(n-1, 'a') + f(n-1, 'b') + f(n-1, 'o');
    // }
    int countPaths(int n){
        // long long int res = f(n, 'o')%mod;
        // return res%mod;
        
        vector<vector<long long int>> dp(n, vector<long long int> (4, 0));
        
        dp[0][0] = 1;
        dp[0][1] = dp[0][1] = dp[0][2] = 0;
        
        for(int i=1;i<n;i++){
            dp[i][0] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
            dp[i][1] = (dp[i-1][0]+dp[i-1][2]+dp[i-1][3])%mod;
            dp[i][2] = (dp[i-1][1]+dp[i-1][0]+dp[i-1][3])%mod;
            dp[i][3] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][0])%mod;
        }
        
        return (dp[n-1][1]+dp[n-1][2]+dp[n-1][3])%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends