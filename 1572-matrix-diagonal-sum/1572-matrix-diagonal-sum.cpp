class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int i=0, j=0, cnt=0;
        while(cnt != mat.size()){
            sum += mat[i][j];
            i++;
            j++;
            cnt++;
        }
        cnt=0;
        i=0, j=mat[0].size()-1;
         while(cnt != mat.size()){
            sum += mat[i][j];
            i++;
            j--;
            cnt++;
        }
        
        int n=mat.size();
        if(n%2){
            sum -= mat[n/2][n/2];
        }
        return sum;
    }
};