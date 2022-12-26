class Solution {
public:
    bool f(int src, vector<int>& arr, vector<bool>& visited){
        if(src < 0 || src >= arr.size() || visited[src]) return false;
        
        if(arr[src] == 0) return true;
        visited[src] = true;
        
        return f(src + arr[src], arr, visited) || f(src - arr[src], arr, visited);
    }
    bool canReach(vector<int>& arr, int start) {
       vector<bool> visited(arr.size());
       return f(start, arr, visited); 
    }
};