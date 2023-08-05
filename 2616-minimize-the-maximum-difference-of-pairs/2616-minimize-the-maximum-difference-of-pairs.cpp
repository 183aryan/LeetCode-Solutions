class Solution {
public:
    bool check(int x, int p, vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] <= x) {
                p--;
                i++;
            }
        }
        return p <= 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo=0;
        int hi = nums[n-1] - nums[0];
        int ans = -1;
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            
            if(check(mid, p, nums)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};