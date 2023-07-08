class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size() == 0) return 0;
        set<int> s;
        for(int i=0;i<arr.size();i++) s.insert(arr[i]);
        int maxi = 1;
        for(int i=0;i<arr.size();i++){
            if(s.find(arr[i] - 1) == s.end()){
                int cnt = 1;
                while(s.find(arr[i]+cnt) != s.end()){
                    cnt++;
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};