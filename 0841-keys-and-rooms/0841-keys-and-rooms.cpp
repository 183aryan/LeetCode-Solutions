class Solution {
public:
    void f(int src, vector<bool>& visited, vector<vector<int>>& rooms){
        visited[src] = true;
        for(auto it:rooms[src]){
            if(not visited[it]) f(it, visited, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        f(0, visited, rooms);
        
        for(auto it:visited){
            if(it == false) return false;
        }
        
        return true;
    }
};