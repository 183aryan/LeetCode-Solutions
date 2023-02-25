class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> left(nums.size()), right(nums.size());
        
        left[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            left[i] = max(left[i-1], nums[i]);
        }
        
        right[nums.size() - 1] = nums[nums.size() - 1];
        for(int i=nums.size()-2;i>=0;i--){
            right[i] = min(right[i+1], nums[i]);
        }
        
        int beauty=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i] > left[i-1] and nums[i] < right[i+1]) beauty += 2;
            else if(nums[i] > nums[i-1] and nums[i] < nums[i+1]) beauty += 1;
        }
        
        return beauty;
    }
};