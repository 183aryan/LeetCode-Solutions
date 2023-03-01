class Solution {
public:
    // vector<int> v;
    void merge(vector<int>& nums, int lo, int mid, int hi){
        // if (lo >= hi) return;
        // v.resize(hi - lo + 1);
        vector<int> v(hi - lo + 1, 0);
        int i = lo;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid and j <= hi){
            if(nums[i] <= nums[j]) v[k++] = nums[i++];
            else v[k++] = nums[j++];
        }
        
        while(i <= mid) v[k++] = nums[i++];
        while(j <= hi) v[k++] = nums[j++];
        
        // k=0;
        // for(int i=0;i<nums.size();i++){
        //     nums[i] = v[k++];
        // }
        k=0;
        for (int i=lo;i<=hi;i++) nums[i] = v[k++];
    }
    void mergeSort(vector<int>& nums, int lo, int hi){
        if(hi <= lo) return;
        int mid = lo + (hi - lo)/2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, hi);
        merge(nums, lo, mid, hi);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums; 
    }
};