// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<N;i++){
            pq.push({B[i],A[i]});
        }
        
        if(T == 0) return 0;
        int res = 0;
        
        while(T>0 and pq.size() > 0){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            while(y-- and T--){
                res += x;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends