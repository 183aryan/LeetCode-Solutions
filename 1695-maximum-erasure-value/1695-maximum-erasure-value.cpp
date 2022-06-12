class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int l=0,r=0,sum = 0,res=0;
        while(r < nums.size()){
            sum += nums[r];
            while(s.find(nums[r]) != s.end()){
                sum -= nums[l];
                s.erase(nums[l]);
                l++;
            }
            s.insert(nums[r]);
            r++;
            res = max(res,sum);
        }
        return res;
    }
};