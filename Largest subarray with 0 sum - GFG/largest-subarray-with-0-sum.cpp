//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        unordered_map<int, int> um;
        int preSum = 0, res = 0;
        for(int i=0;i<n;i++){
            preSum += A[i];
            if(preSum == 0){
                res = max(res, i+1);
            }
            if(um.find(preSum) == um.end()){
                um.insert({preSum, i});
            }
            if(um.find(preSum - 0) != um.end()){
                res = max(res, i - um[preSum - 0]);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends