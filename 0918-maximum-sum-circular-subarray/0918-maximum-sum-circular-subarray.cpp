class Solution {
public:
    int kadnes(vector<int> arr, int n){
        int res = arr[0], mxEnd = arr[0];
        for(int i=1;i<n;i++){
            mxEnd = max(mxEnd+arr[i], arr[i]);
            res = max(res, mxEnd);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        int num = arr.size();
        int maxi = kadnes(arr, num);
        if(maxi < 0) return maxi;
        
        int sum=0;
        for(int i=0;i<num;i++){
            sum += arr[i];
            arr[i] *= -1;
        }
        
        int new_max = sum + kadnes(arr, num);
        
        return max(maxi, new_max);
    }
};