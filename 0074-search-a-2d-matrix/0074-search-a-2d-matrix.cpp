class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo=0, hi = n*m-1;
        
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            
            int ans = matrix[mid/m][mid%m];
            if(target == ans) return true;
            if(ans > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};