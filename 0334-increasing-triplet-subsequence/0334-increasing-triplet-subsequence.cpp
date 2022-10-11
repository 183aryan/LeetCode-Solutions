class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            if(nums[i] > temp.back()) temp.push_back(nums[i]);
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        if(temp.size() >= 3) return true;
        return false;
    }
};