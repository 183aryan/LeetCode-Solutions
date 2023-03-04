class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int cnt=0;
        int i=0;
        int mini=-1, maxi=-1;
        int outer=-1;
        while(i < nums.size()){
            if(nums[i] == minK) mini = i;
            if(nums[i] == maxK) maxi = i;
            if(nums[i] < minK || nums[i] > maxK){
                mini = -1;
                maxi = -1;
                outer = i;
            }
            cnt += max(0LL, 1LL*(min(mini, maxi) - outer));
            i++;
        }
        return cnt;
    }
};