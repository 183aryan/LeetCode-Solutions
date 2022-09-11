class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k){
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({efficiency[i],speed[i]});
        }
        sort(vp.rbegin(), vp.rend());
        
        long long int sum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            sum += vp[i].second;
            pq.push(vp[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum*vp[i].first);
        }
        return ans%MOD;
    }
};