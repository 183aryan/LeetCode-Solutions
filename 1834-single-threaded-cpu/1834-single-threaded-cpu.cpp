class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for(int i=0;i<tasks.size();i++) tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        
        int i=0, time=0;
        
        vector<int> v;
        
        while(i < tasks.size() || !pq.empty()){
            if(pq.empty()){
                time = max(time, tasks[i][0]); 
            }
            
            while(i < tasks.size() and time >= tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            pair<long long int, long long int> p = pq.top();
            pq.pop();
            time += p.first;
            
            v.push_back(p.second);
        }
        
        return v;
    }
};