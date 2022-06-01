class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
    
        for(int i = 1 ; i < nums.size() ; i++){
            nums[i] += nums[i-1];
        }
        
        // for(int i = 0;i < res.size();i++){
        //     cout << nums[i] << " ";
        // }
        return nums;
    }
};