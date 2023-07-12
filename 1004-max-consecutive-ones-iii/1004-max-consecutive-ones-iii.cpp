class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int cnt=0;
        int maxi=0;
        // unordered_map<int, int> um;
        while(j<nums.size()){
            if(nums[j] == 0) cnt++;
            while(cnt>k){
                if(nums[i] == 0) cnt--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};