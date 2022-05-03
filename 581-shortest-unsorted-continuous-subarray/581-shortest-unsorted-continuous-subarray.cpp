class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> num(nums);
        sort(num.begin(),num.end());
        
        int first = 0, second = nums.size()-1;
        
        while(first < nums.size() and nums[first] == num[first]) first++;
        while(second > first and nums[second] == num[second]) second--;
        
        return second - first + 1;
    }
};