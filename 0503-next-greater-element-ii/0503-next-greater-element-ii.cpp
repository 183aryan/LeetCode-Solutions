class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int, int> um;
        stack<int> s;
        int n = nums.size();
        vector<int> v(n, -1);
        // s.push(nums[n-1]);
        
        for(int i=2*n-1;i>=0;i--){
            while(s.size() and s.top() <= nums[i%n]){
                s.pop();
            }
            if(!s.empty() && (i < n)) v[i] = s.top();
            s.push(nums[i%n]);
        }
        // reverse(v.begin(), v.end());
        return v;
    }
};