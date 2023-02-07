//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
            int prod=1;
            int tLen=0;
            int ansLen=0;
            for(int i=0;i<n;i++){
                if(arr[i] == 0){
                    tLen=0;
                    prod=1;
                    continue;
                }
                else if(arr[i] > 0){
                    prod *= 1;
                    tLen++;
                }
                else{
                    prod *= -1;
                    tLen++;
                }
                if(prod > 0) ansLen = max(ansLen, tLen);
            }
            prod = 1;
            tLen=0;
            for(int i=n-1;i>=0;i--){
                if(arr[i] == 0){
                    tLen=0;
                    prod=1;
                }
                else if(arr[i] > 0){
                    prod *= 1;
                    tLen++;
                }
                else{
                    prod *= -1;
                    tLen++;
                }
                if(prod > 0) ansLen = max(ansLen, tLen);
            }
            return ansLen;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends