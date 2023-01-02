class Solution {
public:
    bool detectCapitalUse(string word) {
        int cntu=0,cntl=0;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])) cntu++;
            if(islower(word[i])) cntl++;
        }
        if(cntu == word.size() || cntl == word.size()) return true;
        if((cntl == word.size()-1) and isupper(word[0])) return true;
        
        return false;
    }
};