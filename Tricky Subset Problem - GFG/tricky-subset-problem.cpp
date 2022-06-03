// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        // code here
        vector<long long> newA;
        newA.push_back(S);
        long long sum = S;
        for(int i = 1 ; i <= N && sum <= X; i++){
            newA.push_back(sum + A[i - 1]);
            sum += newA[i];
        }
    
        for(int i = newA.size() - 1 ; i >= 0 ;i--){
            if(newA[i] <= X)
            X -= newA[i];
        }
        return X == 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends