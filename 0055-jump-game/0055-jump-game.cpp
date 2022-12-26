class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind = nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(i + nums[i] >= ind) ind = i;
        }
        return ind == 0;
    }
};