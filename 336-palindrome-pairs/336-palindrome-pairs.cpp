class Solution {
public:
    bool isPal(string s){
        int i=0,j=s.size()-1;
        while(j > i){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> v;
        if(words.size() < 2) return v;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();++i){
            auto s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
        }
        
        for(int i=0;i<words.size();++i){
            for(int j=0;j<=words[i].size();++j){
                string s1 = words[i].substr(0,j); // prefix
                string s2 = words[i].substr(j); // suffix
                
                if(m.count(s1) && isPal(s2) && m[s1] != i)
                    v.push_back({i,m[s1]});
                
                if(!s1.empty() && m.count(s2) && isPal(s1) && m[s2] != i)
                    v.push_back({m[s2],i});
                
            }
        }
        return v;
    }
};