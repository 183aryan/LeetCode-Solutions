class Solution {
public:
    bool isPal(string s){
        string s1 = s;
        reverse(s.begin(),s.end());
        return (s == s1);
    }
    int removePalindromeSub(string s) {
        if(isPal(s)) return 1;
        return 2;
    }
};