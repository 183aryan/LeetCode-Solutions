class Solution {
public:
    string removeDuplicates(string s) {
        string s1;
        s1.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s1.back() == s[i]) s1.pop_back();
            else s1.push_back(s[i]);
        }
        return s1;
    }
};