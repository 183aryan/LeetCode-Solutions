class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int secondMax = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] < secondMax) return true;
            while(!s.empty() and s.top() < nums[i]){
                secondMax = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};