// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        //code here
        vector<int> v,minArr(N);
        minArr[N-1] = Arr[N-1];
        for(int i=N-2;i>=0;i--){
            minArr[i] = min(Arr[i],minArr[i+1]);
        }
        
        for(int i=0;i<N;i++){
            int lo = i+1,hi = N-1,ans = -1;
            while(hi>=lo){
                int mid = lo + (hi-lo)/2;
                if(minArr[mid] < Arr[i]){
                    ans = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }
            v.push_back(ans);
        }
        return v;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends