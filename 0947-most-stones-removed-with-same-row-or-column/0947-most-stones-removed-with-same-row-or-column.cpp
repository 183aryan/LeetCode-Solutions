class Solution {
public:
    void dfs(int index, vector<vector<int>>& stones, vector<int>& visited){
        visited[index] = 1;
        
        for(int i=0;i<stones.size();i++){
            if(!visited[i] and (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])) dfs(i, stones, visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> visited(stones.size(), 0);
        int cnt=0;
        for(int i=0;i<stones.size();i++){
            if(visited[i] == false){
                cnt++;
                dfs(i, stones, visited);
            }
        }
        return stones.size() - cnt;
    }
};