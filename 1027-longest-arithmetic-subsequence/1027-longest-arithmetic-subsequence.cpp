class Solution {
public:
    // int f(int index, int diff, vector<int>& nums, unordered_map<int, int> dp[]){
    //     if(index < 0) return 0;
    //     if(dp[index].count(diff)) return dp[index][diff]; 
    //     int ans = 0;
    //     for(int i=index-1;i>=0;i--){
    //         if(nums[index] - nums[i] == diff) ans = max(ans, 1 + f(i, diff, nums, dp));
    //     }
    //     return dp[index][diff] = ans;
    // }
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums.size();
        }
        
        unordered_map<int, int> dp[nums.size()+1];
        int ans = 0;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j]; 
                int cnt=1;
                
                if(dp[j].count(diff)) cnt = dp[j][diff]; 
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};