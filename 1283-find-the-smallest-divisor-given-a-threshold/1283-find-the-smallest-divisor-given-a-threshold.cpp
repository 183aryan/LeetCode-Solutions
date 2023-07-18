class Solution {
public:
    bool check(int x, int divisor, vector<int>& v){
        int sum = 0;
        for(int i=0;i<v.size();i++){
            sum += ceil(1.0*v[i] / x);
        }
        return sum <= divisor;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());
        int ans= -1;
        
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            if(check(mid, threshold, nums)){
                ans = mid;
                hi = mid - 1;
            }else lo = mid + 1;
        }
        return ans;
    }
};