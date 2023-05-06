class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<int> pw(nums.size(), 1);
        
        for(int i=1;i<nums.size();i++){
            pw[i] = (pw[i-1]*2)%mod;
        }
        
        int i=0, j=nums.size()-1, ans=0;
        
        while(j >= i){
            if(nums[i] + nums[j] > target) j--;
            else{
                ans = (ans + pw[j-i])%mod;
                i++;
            }
        }
        return ans;
    }
};