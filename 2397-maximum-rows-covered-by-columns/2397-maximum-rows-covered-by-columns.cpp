class Solution {
public:
    int maxi = -1;
    void f(vector<vector<int>>& mat, int cols, int ind, vector<int>& visited){
        if(cols == 0 || ind == mat[0].size()){
            int cnt = 0;
            for(int i=0;i<mat.size();i++){
                bool flag = true;
                for(int j=0;j<mat[0].size();j++){
                    if(mat[i][j] == 1 and visited[j] == 0){
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
            maxi = max(cnt, maxi);
            return;
        }
        visited[ind] = 1;
        f(mat, cols-1, ind+1, visited);
        visited[ind] = 0;
        f(mat, cols, ind+1, visited);
        return;
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        vector<int> visited(mat[0].size());
        f(mat,cols,0,visited);
        return maxi;
    }
};