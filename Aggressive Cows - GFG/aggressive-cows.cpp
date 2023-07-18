//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool check(vector<int>&stalls, int n, int k, int dist){
        int cnt=1;
        int pivot = stalls[0];
        
        for(int i=1;i<n;i++){
            if(stalls[i]-pivot >= dist){
                cnt++;
                pivot = stalls[i];
            }
            if(cnt == k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int lo=1;
        int hi=stalls[n-1] - stalls[0];
        
        int res=0;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            
            if(check(stalls, n, k, mid)){
                res = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends