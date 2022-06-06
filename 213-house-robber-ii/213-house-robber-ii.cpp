class Solution {
public:
    int f(int n,vector<int>& nums){
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int not_take = prev;
            int curr = max(take,not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(nums.size(),-1);
        if(n == 1) return nums[0];
        vector<int> temp1,temp2;
        
        for(int i=0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1.size(),temp1),f(temp2.size(),temp2));
    }
};