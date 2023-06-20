class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        vector<long long int> prefix(n), suffix(n);
        vector<int> v;
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i];
        }
        
        for(int i=0;i<n;i++){
            if(i-k < 0 || i+k >= n) v.push_back(-1);
            else{
                long long int sum = (suffix[i-k]-suffix[i]) + (prefix[i+k]-prefix[i]) + nums[i];
                v.push_back(sum/(2*k+1));
            }
        }
        return v;
    }
};