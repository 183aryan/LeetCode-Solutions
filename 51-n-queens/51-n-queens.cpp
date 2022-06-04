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
    void recursion(vector<string>& v,int col){
        if(col == v.size()){
            res.push_back(v);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(isSafe(i,v,col)){
                v[i][col] = 'Q';
                recursion(v,col+1);
                v[i][col] = '.';
            }   
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {{}};
        if(n == 1) return {{"Q"}};
        
        vector<string> v(n,string(n,'.'));
        recursion(v,0);
        return res;
    }
};