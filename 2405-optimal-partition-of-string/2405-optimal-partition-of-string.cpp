class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> m;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]){
                cnt++;
                m.clear();
            }
            m[s[i]]++;
        }
        return cnt+1;
    }
};