//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int f(int i, vector<int>& arr, vector<int>& dp, vector<int>& visited){
        if(i < 0 || i >= arr.size()) return 1;
        if(dp[i] != -1) return dp[i];
        if(visited[i] == 1) return 0;
        
        visited[i] = 1;
        
        return dp[i] = f(i+arr[i], arr, dp, visited);
    }
    int goodStones(int n,vector<int> &arr){
        vector<int> dp(n, -1);
        vector<int> visited(n, 0);
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(visited[i] == 0) f(i, arr, dp, visited);
        }
        
        for(int i=0;i<n;i++){
            if(dp[i] == 1) cnt++;
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends