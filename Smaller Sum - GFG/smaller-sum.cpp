//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> v(arr.begin(), arr.end());
        vector<long long> preSum(n, 0);
        vector<long long> ans(n, 0);
        
        sort(v.begin(), v.end());
        
        preSum[0] = v[0];
        for(int i=1;i<n;i++) preSum[i] = preSum[i-1] + v[i];
        
        for(int i=0;i<n;i++){
            int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            if(index == 0) ans[i] = 0;
            else ans[i] = preSum[index-1];
        }
        return ans;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends