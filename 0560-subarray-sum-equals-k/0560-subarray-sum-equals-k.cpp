class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int, int> um;
        // int pre_sum=0;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i=1;i<prefix.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(prefix[i] == k) cnt++;
            if(um.find(prefix[i] - k) != um.end()) cnt += um[prefix[i] - k];
            um[prefix[i]]++;
        }
        return cnt;
    }
};