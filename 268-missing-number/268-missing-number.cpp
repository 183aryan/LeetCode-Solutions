class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int ans = -1;
        for(int i=0;i<=nums.size();i++){
            if(s.find(i) == s.end()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};