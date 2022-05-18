class Solution {
public:
    int dist(vector<int>& v){
        return v[0]*v[0] + v[1]*v[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<points.size();i++){
            pq.push({dist(points[i]),i});
            if(pq.size() > k) pq.pop();
        }
        
        for(int i=0;i<k;i++){
            v.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return v;
    }
};