// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        bool check(int mid,int n){
            int cnt5=0,x = mid;
            // num = mid;
            while(x){
                x /= 5;
                cnt5+=x;
            }
            return (cnt5 >= n);
        }
        int findNum(int n)
        {
        //complete the function here
        int lo = 1,hi = 1e9,mid,ans;
        while(hi >= lo){
            mid = lo + (hi - lo)/2;
            if(check(mid,n)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends