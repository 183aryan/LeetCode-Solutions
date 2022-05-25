// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool check(int i,int j,int n,vector<vector<bool>>& visited){
        if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] == true) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int x1 = KnightPos[0]-1, y1 = KnightPos[1]-1;
	    
	    if(tx == x1 and ty == y1) return 0;
	    
	    vector<vector<bool>> visited(N,vector<bool>(N,false));
	    
	    queue<pair<int,int>> q;
	    q.push({x1,y1});
	    visited[x1][y1] = true;
	    
	    int res = 0;
	    
	    while(!q.empty()){
	        int sz = q.size();
	        res++;
	        while(sz){
	            auto x = q.front();
	            q.pop();
	            
	            int xx = x.first;
	            int yy = x.second;
	            
	            int ax[8] = {1,1,-1,-1,2,-2,2,-2};
	            int ay[8] = {2,-2,2,-2,1,1,-1,-1};
	            
	            for(int i=0;i<8;i++){
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                if(nx == tx and ny == ty) return res;
	                
	                if(check(nx,ny,N,visited) == true){
	                    visited[nx][ny] = true;
	                    q.push({nx,ny});
	                }
	            }
	            sz--;
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends