class Solution {
public:
    int beautySum(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            unordered_map<char, int> um;
            for(int j=i;j<s.size();j++){
                um[s[j]]++;
                int mini = INT_MAX, maxi = INT_MIN;
                for(auto it:um){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                cnt += (maxi - mini);
            }
        }
        return cnt;
    }
};