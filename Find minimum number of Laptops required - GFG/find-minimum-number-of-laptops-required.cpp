//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        vector<pair<int, int>> vp;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<N;i++) vp.push_back({start[i], end[i]});
        sort(vp.begin(), vp.end());
        
        int cnt=0;
        
        for(int i=0;i<N;i++){
            if(pq.empty()){
                cnt++;
                pq.push(vp[i].second);
            }
            else if(pq.top() > vp[i].first){
                cnt++;
                pq.push(vp[i].second);
            }
            else{
                pq.pop();
                pq.push(vp[i].second);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends