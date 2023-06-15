class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> us;
        int res = 1;
        int N = arr.size();
        
        if(N == 0) return 0;
        for(int i=0;i<N;i++) us.insert(arr[i]);
        
        for(int i=0;i<N;i++){
            if(us.find(arr[i]-1) == us.end()){
                int cnt=1;
                
                while(us.find(arr[i]+cnt) != us.end()) cnt++;
                
                res = max(res, cnt);
            }
        }
        return res;
    }
};