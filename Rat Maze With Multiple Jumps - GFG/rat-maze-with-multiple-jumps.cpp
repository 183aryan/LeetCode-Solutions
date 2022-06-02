// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool check(int n,vector<vector<int>>& v,vector<vector<int>>& matrix,int i,int j){
        if(i >= n || j >= n) return false;
    
        v[i][j] = 1;
        if(i == n-1 and j == n-1) return true;
        int jumps = matrix[i][j];
        for(int k=1;k<=jumps;k++){
            if(check(n,v,matrix,i,j+k)) return true;
            if(check(n,v,matrix,i+k,j)) return true;
        }
        v[i][j] = 0;
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   vector<vector<int>> v(n,vector<int>(n,0));
	   if(check(n,v,matrix,0,0)) return v;
	   return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends