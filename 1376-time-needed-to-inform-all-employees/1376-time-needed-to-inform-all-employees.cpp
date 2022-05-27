class Solution {
public:
    unordered_map<int,vector<int>> um;
    int ans = 0,mx = 0;
    
    void DFS(int headID, vector<int>& informTime){
        mx = max(ans,mx);
        for(auto x:um[headID]){
            ans += informTime[headID];
            DFS(x,informTime);
            ans -= informTime[headID];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++){
            int val = manager[i];
            if(val != -1)
            um[val].push_back(i);
        }
        DFS(headID,informTime);
        return mx;
    }
};