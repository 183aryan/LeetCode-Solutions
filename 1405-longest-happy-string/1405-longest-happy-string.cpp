class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        
        string res = "";
        
        while(pq.size() > 1){
            auto t1 = pq.top();
            pq.pop();
            auto t2 = pq.top();
            pq.pop();
            
            if(t1.first >= 2){
                res += t1.second;
                res += t1.second;
                t1.first -= 2;
            }
            else{
                res += t1.second;
                t1.first -= 1;
            }
            
            if(t2.first >= 2 and t2.first >= t1.first){
                res += t2.second;
                res += t2.second;
                t2.first -= 2;
            }
            else{
                res += t2.second;
                t2.first -= 1;
            }
            
            if(t1.first > 0) pq.push(t1);
            if(t2.first > 0) pq.push(t2);
        }
        if(pq.empty()) return res;
        if(pq.top().first >= 2){
            res += pq.top().second;
            res += pq.top().second;
        }
        else{
            res += pq.top().second;
        }
        
        return res;
    }
};