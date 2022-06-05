class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(int row,vector<string>& v,int col){
        for(int i=col;i>=0;i--){
            if(v[row][i] == 'Q') return false;
        }
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
            if(v[i][j] == 'Q') return false;
        }
        for(int i=row,j=col;i < v.size() and j>=0;i++,j--){
            if(v[i][j] == 'Q') return false;
        }
        return true;
    }
    int recursion(vector<string>& v,int col){
        int cnt = 0;
        if(col == v.size()){
            res.push_back(v);
            return 1;
        }
        for(int i=0;i<v.size();i++){
            if(isSafe(i,v,col)){
                v[i][col] = 'Q';
                cnt += recursion(v,col+1);
                v[i][col] = '.';
            }   
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<string> v(n,string(n,'.'));
        return recursion(v,0);
        // return res;
    }
};