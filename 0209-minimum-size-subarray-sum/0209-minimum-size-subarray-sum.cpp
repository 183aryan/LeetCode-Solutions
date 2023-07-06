class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = 0, hi = 0, sum = 0;
        int mini = INT_MAX;
        
        for(hi=0;hi<nums.size();hi++){
            sum += nums[hi];
            
            while(sum >= target){
                mini = min(mini, hi - lo + 1);
                sum -= nums[lo];
                lo++;
            }
        }
        return mini != INT_MAX ? mini : 0; 
    }
};