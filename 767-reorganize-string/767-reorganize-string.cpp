class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto x:m) pq.push({x.second,x.first});
        
        while(pq.size() > 1){
            auto t1 = pq.top();
            pq.pop();
            auto t2 = pq.top();
            pq.pop();
            
            res += t1.second;
            res += t2.second;
            
            t1.first--;
            t2.first--;
            
            if(t1.first > 0) pq.push(t1);
            if(t2.first > 0) pq.push(t2);         
        }
        
        if(!pq.empty()){
            if(pq.top().first > 1) return "";
            else res += pq.top().second;
        }
        return res;
    }
};