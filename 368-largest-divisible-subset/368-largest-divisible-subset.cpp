class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi = 1;
        int last=0;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev] == 0 and 1+dp[prev]>dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[last]);
        while(hash[last] != last){
            last = hash[last];
            temp.push_back(nums[last]);
        }
        
        return temp;
    }
};