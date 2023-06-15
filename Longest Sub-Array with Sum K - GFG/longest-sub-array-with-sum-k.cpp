//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int> um;
        int preSum=0, res=0;
        
        for(int i=0;i<N;i++){
            preSum += A[i];
            if(preSum == K) res = max(res, i+1);
            if(um.find(preSum) == um.end()){
                um[preSum] = i;
            }
            if(um.find(preSum - K) != um.end()){
                res = max(res, i - um[preSum - K]);
            }
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends