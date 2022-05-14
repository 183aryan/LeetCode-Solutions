class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        // for finding all xor of the matrix...
        int n = matrix.size();
        int m = matrix[0].size();
        
        // firstly in the matrix.
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j] ^= matrix[i][j-1];
            }
        }
        
        // now 3X5 -> 5X3 me.....for overall xor.....of a element.
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[j][i] ^= matrix[j-1][i];
            }
        }
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pq.size() < k) pq.push(matrix[i][j]);
                else{
                    if(pq.top() < matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};