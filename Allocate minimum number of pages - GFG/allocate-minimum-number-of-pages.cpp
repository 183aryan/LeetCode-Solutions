//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool check(int x, int n, int m, int a[]){
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+a[i] > x){
                cnt++;
                sum=a[i];
            }
            else sum += a[i];
        }
        return (cnt<=m);
    }
    int findPages(int a[], int n, int m) 
    {
        if(m > n) return -1;
        int lo=*max_element(a, a+n);
        int hi=accumulate(a, a+n, 0);
        
        int ans=-1;
        
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(check(mid, n, m, a)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends