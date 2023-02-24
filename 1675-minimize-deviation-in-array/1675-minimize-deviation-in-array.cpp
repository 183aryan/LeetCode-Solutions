class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1) nums[i] *= 2;
        }
        
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        
        int ans = mx - mn;
        
        priority_queue<int> pq;
        
        for(auto it:nums) pq.push(it);
        
        while(pq.size()){
            int x = pq.top();
            pq.pop();
            
            ans = min(ans, x - mn);
            if(x&1) break;
            x /= 2;
            mn = min(mn, x);
            pq.push(x);
        }
        return ans;
    }
};