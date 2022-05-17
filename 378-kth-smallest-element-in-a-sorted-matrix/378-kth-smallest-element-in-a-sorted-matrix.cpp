class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                v.push_back(matrix[i][j]);
            }
        }
        int res = 0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(k-1 == i){
                res = v[i];
                break;
            }
        }
        return res;
    }
};