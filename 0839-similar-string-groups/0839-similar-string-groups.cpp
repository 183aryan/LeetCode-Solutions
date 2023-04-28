class Solution {
public:
    void dfs(int index, vector<string>& strs, vector<int>& visited){
        visited[index] = 1;
        for(int i=0;i<strs.size();i++){
            if(visited[i] == 0){
                int diff=0;
                for(int j=0;j<strs[0].size();j++){
                    if(strs[i][j] != strs[index][j]) diff++;
                }
                if(diff == 2 || diff == 0) dfs(i, strs, visited);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int cnt=0;
        vector<int> visited(strs.size(), 0);
        for(int i=0;i<strs.size();i++){
            if(visited[i] == 0){
                cnt++;
                dfs(i, strs, visited);
            }
        }
        return cnt;
    }
};