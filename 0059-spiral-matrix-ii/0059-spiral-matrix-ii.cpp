class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int> (n));
        int cnt = 1, i = 0;
        
        while(cnt <= n*n){
            int j = i;
            while(j < n - i){
                v[i][j++] = cnt++;
            }
            j = i + 1;
            while(j < n - i){
                v[j++][n - i - 1] = cnt++;
            }
            j = n - i - 2;
            while(j > i){
                v[n - i - 1][j--] = cnt++;
            }
            j = n - i - 1;
            while(j > i){
                v[j--][i] = cnt++;
            }
            i++;
        }
        return v;
    }
};