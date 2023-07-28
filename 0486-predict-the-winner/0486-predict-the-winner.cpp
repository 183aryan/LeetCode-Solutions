class Solution {
public:
    int f(int i, int j, vector<int>& nums, bool flag){
        if(i > j) return 0;
        int res = 0;
        if(flag){
            res = max(nums[i] + f(i+1, j, nums, false), nums[j] + f(i, j-1, nums, false));
        }
        else res = min(-nums[i] + f(i+1, j, nums, true), -nums[j] + f(i, j-1, nums, true));
        
        return res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        bool flag=true;
        int ans = f(0, nums.size()-1, nums, flag);
        return (ans >= 0) ? true : false;
    }
};