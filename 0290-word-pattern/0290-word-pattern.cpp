class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> um;
        set<char> stc;
        set<string> sts;
        vector<string> vs;
        istringstream iss(s);
        string str;
        
        while(iss >> str){
            vs.push_back(str);
            sts.insert(str);
        }
        for(auto it:pattern) stc.insert(it);
        
        if(pattern.size() != vs.size() || stc.size() != sts.size()) return false;
        
        for(int i=0;i<vs.size();i++){
            if(um.count(pattern[i])){
                if(um[pattern[i]] != vs[i]) return false;
            }
            else um[pattern[i]] = vs[i];
        }
        return true;
    }
};