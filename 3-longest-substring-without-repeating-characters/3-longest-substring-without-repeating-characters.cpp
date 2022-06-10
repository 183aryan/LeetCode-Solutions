class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1) return 1;
        unordered_set<char> st;
        
        int cnt = 0,res = 0;
        int j=0;
        for(int i=0;i<s.size();i++){
            while(st.find(s[i]) != st.end()){
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            
            res = max(res,(int)st.size());
        }
        return res;
    }
};