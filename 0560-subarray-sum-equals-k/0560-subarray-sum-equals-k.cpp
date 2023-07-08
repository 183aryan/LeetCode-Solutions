class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int preSum = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            if(preSum == k) cnt++;
            if(um.find(preSum - k) != um.end()) cnt += um[preSum - k];
            um[preSum]++;
        }
        return cnt;
    }
};