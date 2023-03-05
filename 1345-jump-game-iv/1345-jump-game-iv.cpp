class Solution {
public:
//     int f(int src, vector<int>& arr, vector<bool>& visited){
//         if(src < 0 || src > arr.size() || visited[src]) return 0;
        
//         if(src == arr.size()-1) return 1;
        
//         return 
//     }
    int minJumps(vector<int>& arr) {
        // vector<bool> visited(arr.size(), false);
        // return f(0, arr, visited);
        unordered_map<int , vector<int>> um;
        for(int i=0;i<arr.size();i++){
            um[arr[i]].push_back(i);
        }
        
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        int cnt_steps = 0;
        
        while(q.size()){
            int sz = q.size();
            cnt_steps++;
            for(int i=0;i<sz;i++){
                int j=q.front();
                q.pop();
                
                if(j == arr.size()-1) return cnt_steps-1;
                
                vector<int>& v = um[arr[j]];
                if(j-1 >= 0) v.push_back(j-1);
                if(j+1 < arr.size()) v.push_back(j+1);
                
                for(auto it:v){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
                um[arr[j]].clear();
            }
        }
        return -1;
    }
};