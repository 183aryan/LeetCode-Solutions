class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0, hi=arr.size()-1;
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1]) return mid;
            if(arr[mid] > arr[mid+1]) {
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return -1;
    }
};