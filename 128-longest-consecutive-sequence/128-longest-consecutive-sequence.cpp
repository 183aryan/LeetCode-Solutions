class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if(nums.size() == 0) return 0;
            sort(nums.begin(),nums.end());
            
            int res = 0, cnt = 1;
            
            for(int i=1;i<nums.size();i++){
                if(nums[i] == nums[i-1]+1){
                    cnt++;
                }
                else if(nums[i] != nums[i-1]){
                    res = max(cnt,res);
                    cnt = 1;
                }
            }
            res = max(cnt,res);
            return res;
        }
};