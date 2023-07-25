//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadnes(int arr[], int n){
        int res = arr[0], mxEnd = arr[0];
        for(int i=1;i<n;i++){
            mxEnd = max(mxEnd+arr[i], arr[i]);
            res = max(res, mxEnd);
        }
        return res;
    }
    int circularSubarraySum(int arr[], int num){
        int maxi = kadnes(arr, num);
        if(maxi < 0) return maxi;
        
        int sum=0;
        for(int i=0;i<num;i++){
            sum += arr[i];
            arr[i] *= -1;
        }
        
        int new_max = sum + kadnes(arr, num);
        
        return max(maxi, new_max);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends