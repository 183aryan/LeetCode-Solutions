class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix.size(), m = matrix[0].size();
        
        int sr = 0, sc = 0, er = n - 1, ec = m - 1;
        int cnt = 0;
        int t = n*m;
        
        while(cnt < t){
            for(int i=sc;cnt<t and i<=ec;i++){
                v.push_back(matrix[sr][i]);
                cnt++;
            }
            sr++;
            
            for(int i=sr;cnt<t and i<=er;i++){
                v.push_back(matrix[i][ec]);
                cnt++;
            }
            ec--;
            
            for(int i=ec;cnt<t and i>=sc;i--){
                v.push_back(matrix[er][i]);
                cnt++;
            }
            er--;
            
            for(int i=er;cnt<t and i>=sr;i--){
                v.push_back(matrix[i][sc]);
                cnt++;
            }
            sc++;
        }
        return v;
    }
};