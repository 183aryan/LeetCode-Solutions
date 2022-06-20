class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s,s1;
        for(int i=0;i<words.size();i++) s.insert(words[i]);
        for(int i=0;i<words.size();i++) s1.insert(words[i]);
        int cnt=0;
        for(auto x:words){
            for(int i=1;i<x.size();i++){
                if(s1.find(x.substr(i)) != s1.end()){
                    s1.erase(x.substr(i));
                    cnt++;
                }
            }    
        }
        int len = 0;
        for(auto x:s1){
            len += x.size() + 1;
        }
        return len;
    }
};