class Solution {
public:
    struct mycompare{
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(pq.size() < k) pq.push({nums1[i], nums2[j]});
                else if(nums1[i]+nums2[j] < pq.top().first + pq.top().second){
                    pq.pop();
                    pq.push({nums1[i], nums2[j]});
                }
                else break;
            }
        }
        
        while(pq.size() > 0){
            ans.clear();
            ans.push_back(pq.top().first);
            ans.push_back(pq.top().second);
            v.push_back(ans);
            pq.pop();
        }
        return v;
    }
};