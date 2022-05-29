class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            visited.insert(x);
            for(auto it:rooms[x]){
                if(visited.find(it) == visited.end()) q.push(it);
            }
        }
        return visited.size() == rooms.size();
    }
};