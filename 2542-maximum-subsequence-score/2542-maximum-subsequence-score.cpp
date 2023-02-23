class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> vp;
        for(int i=0;i<nums1.size();i++) vp.push_back({nums2[i], nums1[i]});
        sort(vp.rbegin(), vp.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long int mini=INT_MAX;
        long long int sum=0;
        long long int ans=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            mini = min(mini, 1LL*vp[i].first);
            sum += vp[i].second;
            pq.push(vp[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) ans = max(ans, sum*mini);
        }
        return ans;
    }
};