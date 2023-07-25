class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0, hi=arr.size()-1;
        int ans;
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] > arr[mid+1]) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};