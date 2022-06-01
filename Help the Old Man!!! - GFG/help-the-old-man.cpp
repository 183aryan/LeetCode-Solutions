// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void toh(int src,int help,int des,vector<pair<int,int>>& vp,int N){
        if(N==1){ 
            vp.push_back({src,des});
            return;
        }    
        toh(src,des,help,vp,N-1);
        vp.push_back({src,des});
        toh(help,src,des,vp,N-1);
    }
    vector<int> shiftPile(int N, int n){
        // code here
        vector<pair<int,int>> vp;
        int src = 1,des = 3,help = 2;
        toh(src,help,des,vp,N);
        auto x = vp[n-1];
        return {x.first,x.second};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends