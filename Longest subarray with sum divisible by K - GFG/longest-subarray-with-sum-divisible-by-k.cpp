// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int> um;
	    um[0] = -1;
	    int sum = 0,res=0;
	    for(int i=0;i<n;i++){
	        sum = (sum+arr[i])%k;
	        if(sum < 0) sum = (sum+k)%k;
	        if(um.find(sum) != um.end()){
	            res = max(i-um[sum],res);
	        }
	        else um[sum] = i; 
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends