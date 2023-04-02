class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vp;
        
        for(int i=0;i<profit.size();i++){
            vp.push_back({difficulty[i], profit[i]});
        }
        
        sort(vp.begin(), vp.end());
        sort(worker.begin(), worker.end());
        
        int maxi=0, ans=0;
        int i=0;
        for(auto it:worker){
            while(i < profit.size() and it>=vp[i].first){
                maxi = max(maxi, vp[i].second);
                i++;
            }
            ans += maxi;
        }
        return ans;
    }
};