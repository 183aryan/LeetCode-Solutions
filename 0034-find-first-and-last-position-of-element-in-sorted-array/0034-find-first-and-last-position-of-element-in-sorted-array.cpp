class Solution {
public:
    int firstOcc(vector<int>& nums, int lo, int hi, int x){
        if (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (x < nums[mid]) return firstOcc(nums, lo, mid - 1, x);
            else if (x > nums[mid]) return firstOcc(nums, (mid + 1), hi, x);
            else {
                if(mid == 0 || nums[mid-1] != nums[mid]) return mid;
                return firstOcc(nums, lo, mid - 1, x);
            }
        }
        return -1;
    }
    
    int lastOcc(vector<int>& nums, int lo, int hi, int x){
        if(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            if (x < nums[mid]) return lastOcc(nums, lo, mid - 1, x);
            else if (x > nums[mid]) return lastOcc(nums, mid + 1, hi, x);
            else {
                if(mid == nums.size()-1 || nums[mid] != nums[mid + 1]) return mid;
                return lastOcc(nums, mid + 1, hi, x);
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int first = firstOcc(nums,0, nums.size()-1, target);
        int last = lastOcc(nums, 0, nums.size()-1, target);
        
        return {first, last};
    }
};