class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        if(nums.size() == 1) return nums[0];
        int ans = INT_MAX;
        while(hi > lo){
            int mid = lo + (hi - lo) / 2;
            
            if(nums[lo] <= nums[mid] and nums[mid] <= nums[hi]){
                // lo = lo + 1;
                hi = hi - 1;
            }
            else if(nums[lo] <= nums[mid]){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return nums[lo];
    }
};