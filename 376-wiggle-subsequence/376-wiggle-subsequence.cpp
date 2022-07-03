class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prev = 0, curr = 0,cnt = 1;
        for(int i=1;i<nums.size();i++){
            curr = nums[i] - nums[i-1];
            if((curr > 0 and prev <= 0) || (curr < 0 and prev >= 0)){
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};