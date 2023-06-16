class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left=0;
        int res = 0;
        long long int total = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int right=0;right<nums.size();++right){
            total += nums[right];
            while(1LL*nums[right]*(right-left+1) > total + k){
                total -= nums[left];
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};