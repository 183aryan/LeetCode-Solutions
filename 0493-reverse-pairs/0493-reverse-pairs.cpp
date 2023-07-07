class Solution {
public:
    int cnt = 0;
    void cntPairs(vector<int>& arr, int lo, int mid, int hi){
        int right = mid+1;
        for(int i=lo;i<=mid;i++){
            while(right <= hi and arr[i] > 1LL*2*arr[right]) right++;
            cnt += (right - (mid + 1));
        }
    }
    void merge(vector<int>& arr, int lo, int mid, int hi){
        int n1 = mid - lo + 1, n2 = hi - mid;
        int left[n1], right[n2];
        for(int i=0;i<n1;i++) left[i] = arr[lo+i];
        for(int i=0;i<n2;i++) right[i] = arr[mid+i+1];
        int i=0, j=0, k=lo;
        while(i < n1 and j < n2){
            if(left[i] <= right[j]){
                arr[k++] = left[i++];
            }
            else arr[k++] = right[j++];
        }
        while(i < n1) arr[k++] = left[i++];
        while(j < n2) arr[k++] = right[j++];
    }
    void mSort(vector<int>& arr, int lo, int hi){
        if(lo >= hi) return;
        int mid = (lo + hi)/2;
        mSort(arr, lo, mid);
        mSort(arr, mid+1, hi);
        cntPairs(arr, lo, mid, hi);
        merge(arr, lo, mid, hi);
    }
    
    int reversePairs(vector<int>& nums) {
        mSort(nums, 0, nums.size()-1);
        return cnt;
    }
};