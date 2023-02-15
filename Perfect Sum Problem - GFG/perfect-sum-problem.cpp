//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1000000007;
	int f(int i, int arr[], vector<vector<int>>& dp, int sum){
	   // if(sum == 0) return 1;
	   // if(i == 0) return (arr[i] == sum);
	   if(i == 0 and sum != 0) return 0;
	   if(sum == 0 and i == 0) return 1;
	    
	    if(dp[i][sum] != -1) return dp[i][sum];
	    
	    int notPick = f(i-1, arr, dp, sum)%mod;
	    int pick = 0;
	    if(arr[i-1] <= sum) pick = f(i-1, arr, dp, sum - arr[i-1])%mod;
	    
	    return dp[i][sum] = (pick+notPick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return f(n, arr, dp, sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends