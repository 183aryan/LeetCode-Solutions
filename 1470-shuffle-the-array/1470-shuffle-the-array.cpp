class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n);
        // int lf = nums[0]; 0,2,4
        // int rt = nums[n]; 1,3,5
        
        for(int i=0;i<n;i++){
            v[2*i] = nums[i];
            v[2*i + 1] = nums[n+i];
        }
        return v;
    }
};