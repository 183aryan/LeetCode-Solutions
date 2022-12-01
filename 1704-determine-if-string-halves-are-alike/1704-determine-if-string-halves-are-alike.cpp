class Solution {
public:
    int countVowel(string& s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u') cnt++;
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        string low_s;
        
        for(int i=0;i<s.size();i++) low_s += tolower(s[i]);
        
        string s1 = low_s.substr(0, s.size()/2);
        string s2 = low_s.substr(s.size()/2);
        
        int x = countVowel(s1);
        int y = countVowel(s2);
        
        return x == y;
    }
};