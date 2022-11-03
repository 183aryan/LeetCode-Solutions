class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        set<string> visited;
        q.push(start);
        visited.insert(start);
        
        int cnt=0;
        
        while(q.size()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto x = q.front();
                q.pop();
                
                if(x == end) return cnt;
                
                for(auto it:"ACGT"){
                    for(int j=0;j<x.size();j++){
                        string adjacent = x;
                        adjacent[j] = it;
                        if(!visited.count(adjacent) and find(bank.begin(), bank.end(), adjacent) != bank.end()){
                            q.push(adjacent);
                            visited.insert(adjacent);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};