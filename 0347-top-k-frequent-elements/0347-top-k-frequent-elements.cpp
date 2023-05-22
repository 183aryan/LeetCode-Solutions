class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        vector<int> v;
        priority_queue<pair<int,int>> pq;
    
        for(auto x:um){
            pq.push({x.second,x.first});
        }
        int cnt=0;
        while(cnt != k){
            v.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return v;
    }
};