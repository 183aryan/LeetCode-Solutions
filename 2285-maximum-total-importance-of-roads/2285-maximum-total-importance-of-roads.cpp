class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> in_degree(n);
        for(auto r:roads){
            in_degree[r[0]]++;
            in_degree[r[1]]++;
        }
        
        sort(begin(in_degree),end(in_degree));
        
        long long res = 0;
        for(int i=0;i<n;i++){
            res += in_degree[i]*(i+1);
        }
        return res;
    }
};