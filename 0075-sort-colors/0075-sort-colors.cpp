class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid = 0;
        while(hi >= mid){
            if(nums[mid] == 0){
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[hi], nums[mid]);
                hi--;
            }
        }
    }
};