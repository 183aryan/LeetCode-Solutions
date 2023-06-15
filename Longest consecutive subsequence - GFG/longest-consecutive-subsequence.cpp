//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> us;
        int res = 1;
        
        for(int i=0;i<N;i++) us.insert(arr[i]);
        
        for(int i=0;i<N;i++){
            if(us.find(arr[i]-1) == us.end()){
                int cnt=1;
                
                while(us.find(arr[i]+cnt) != us.end()) cnt++;
                
                res = max(res, cnt);
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends