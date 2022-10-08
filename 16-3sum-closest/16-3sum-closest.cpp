class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1, k=nums.size()-1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if(abs(sum - target) < abs(ans - target)) ans = sum;
                if(sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};