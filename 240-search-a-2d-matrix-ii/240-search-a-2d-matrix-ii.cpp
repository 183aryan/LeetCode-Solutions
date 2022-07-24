class Solution {
public:
    bool f(vector<vector<int>>& matrix,int i,int j,int& target,int& n,int& m){
        
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
            return false;
        
        if(matrix[i][j] == target) return true;
        
        if(matrix[i][j] > target){
            return f(matrix,i,j-1,target,n,m);
        }  
        else{
            return f(matrix,i+1,j,target,n,m);
        }    
    } 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i=0,j=m-1;
        
        return f(matrix,0,m-1,target,n,m);
    }
};