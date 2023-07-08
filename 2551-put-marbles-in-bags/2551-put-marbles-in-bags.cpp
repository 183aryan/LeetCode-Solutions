class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> v;
        
        for(int i=0;i<weights.size()-1;i++){
            v.push_back(weights[i] + weights[i+1]);
        }
        sort(begin(v), end(v));
        
        long long mini = 0;
        long long maxi = 0;
        
        for(int i=0;i<k-1;i++){
            mini += v[i];
            maxi += v[v.size() - i - 1];
        }
        return maxi - mini;
    }
};