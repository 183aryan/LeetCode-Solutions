class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> um1, um2;
        for(int i=0;i<t.size();i++){
            um1[t[i]]++;
        }
        int n = um1.size();
        int j=0;
        int maxi=INT_MAX;
        int x= -1;
        int y = -1;
        set<char> st;
        for(int i=0;i<s.size();i++){
            um2[s[i]]++;
            
            if(um2[s[i]] == um1[s[i]]) st.insert(s[i]);
            
            if(um1.find(s[i]) != um1.end()){
                while(um2[s[j]] > um1[s[j]] and st.size() == n){
                    um2[s[j]]--;
                    j++;
                }
            }
            
            if(st.size() == n){
                if(i-j+1<maxi){
                    x = i;
                    y = j;
                    maxi = x - y + 1;
                }
            }
        }
        if(x == -1) return "";
        return s.substr(y, maxi);
    }
};