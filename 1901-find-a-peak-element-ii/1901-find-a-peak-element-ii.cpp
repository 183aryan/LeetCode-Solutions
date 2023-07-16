class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        int d[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int ii=0; ii<4; ii++){
            int new_i = i + d[ii][0];
            int new_j = j + d[ii][1];
            if(new_i >= 0 && new_j >= 0 && new_i < n && new_j < m && mat[new_i][new_j] > mat[i][j]){
                return false;
            }
        }
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(check(i, j, mat)){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};