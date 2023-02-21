class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int lo=0, hi=nums.size()-1;
        int mid;
        while(hi >= lo){
            mid = lo + (hi - lo)/2;
            
            if(mid%2 == 0 and nums[mid] == nums[mid+1]){
                lo = mid+1;
            }
            else if(mid%2 == 0 and nums[mid] != nums[mid+1]){
                hi = mid-1;
            }
            else if(mid%2 and nums[mid-1] == nums[mid]){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return nums[lo];
    }
};