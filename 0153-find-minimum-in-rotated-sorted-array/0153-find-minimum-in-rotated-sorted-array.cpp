class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int ans = INT_MAX;
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            
            if(nums[lo] <= nums[mid]){
                ans = min(ans, nums[lo]);
                lo = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                hi = mid - 1;
            }
        }
        return ans;
    }
};