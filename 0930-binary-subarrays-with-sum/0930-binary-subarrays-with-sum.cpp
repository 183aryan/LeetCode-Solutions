class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> um;
        int sum = 0;
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum == goal) cnt++;
            cnt += um[sum - goal];
            um[sum]++;
        }
        return cnt;
    }
};