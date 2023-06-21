class Solution {
public:
    long long int f(int med, vector<int>& nums, vector<int>& cost){
        long long int res = 0;
        for(int i=0;i<nums.size();i++){
            res += 1LL*abs(nums[i] - med)*cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> vp;
        for(int i=0;i<nums.size();i++) vp.push_back({nums[i], cost[i]});
        
        sort(vp.begin(), vp.end());
        
        long long int sum = 0, total = 0, median;
        
        for(int i=0;i<cost.size();i++) sum += cost[i];
        
        int i = 0;
        
        while(total < (sum+1)/2 and i < nums.size()){
            total += vp[i].second;
            median = vp[i++].first;
        }
        return f(median, nums, cost);
    }
};