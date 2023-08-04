class Solution {
public:
    void f(int idx, vector<int>& nums, vector<vector<int>>& v){
        if(idx == nums.size()){
            v.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=idx;i<nums.size();i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[i], nums[idx]);
            f(idx+1, nums, v);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        f(0, nums, v);
        return v;
    }
};