class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            
            if((mid == 0 || nums[mid-1] < nums[mid]) and (mid == nums.size()-1 || nums[mid] > nums[mid+1])) return mid; 
            
            if(mid > 0 and nums[mid+1] < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};