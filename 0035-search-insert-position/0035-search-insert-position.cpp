class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        int mid;
        int ans;
        
        while(hi >= lo){
            mid = lo + (hi - lo)/2;
            if(nums[mid] > target){
                hi = mid-1;
            }
            else if(nums[mid] < target){
                lo = mid+1;
            }
            else{
                return mid;
            }
        }
        return lo; // as lo stores the index
    }
};