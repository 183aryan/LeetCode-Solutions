class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(int col,vector<string>& v,int row){
        for(int i=row;i>=0;i--){
            if(v[i][col] == 'Q') return false;
        }
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
            if(v[i][j] == 'Q') return false;
        }
        for(int i=row,j=col;i>=0 and j < v.size();i--,j++){
            if(v[i][j] == 'Q') return false;
        }
        return true;
    }
    void recursion(vector<string>& v,int row){
        if(row == v.size()){
            res.push_back(v);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(isSafe(i,v,row)){
                v[row][i] = 'Q';
                recursion(v,row+1);
                v[row][i] = '.';
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