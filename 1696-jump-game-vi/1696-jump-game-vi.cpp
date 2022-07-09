class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> v(n);
        v[n-1] = nums[n-1];
        dq.push_back(n-1);
        
        for(int i=n-2;i>=0;i--){
            if(dq.front()-i > k) dq.pop_front();
            
            v[i] = nums[i] + v[dq.front()];
            while(dq.size() and v[dq.back()] < v[i]) dq.pop_back();
            
            dq.push_back(i);
        }
        return v[0];
    }
};