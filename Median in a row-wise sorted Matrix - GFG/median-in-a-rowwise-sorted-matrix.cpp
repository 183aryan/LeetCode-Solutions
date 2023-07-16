//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int lo=0, hi=1e9;
        int n = R*C;
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            int cnt=0;
            for(int i=0;i<R;i++){
                int l=0, r=C-1;
                while(r>=l){
                    int m = l + (r - l) / 2;
                    if(matrix[i][m] <= mid) l = m + 1;
                    else r = m - 1;
                }
                cnt += l;
            }
            if(cnt <= n/2){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return lo;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends