class Solution {
public:
    void f(int index, vector<int>& nums, vector<vector<int>>& v){
        if(index == nums.size()){
            v.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i], nums[index]);
            f(index+1, nums, v);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        // USING STL
//         sort(nums.begin(), nums.end());
//         v.push_back(nums);
        
//         while(next_permutation(nums.begin(), nums.end())){
//             v.push_back(nums);
//         }
//         return v;
        
        // Backtracking
        f(0, nums, v);
        return v;
    }
};