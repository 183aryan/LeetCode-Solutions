class Solution {
public:
    bool isVowel(char x){
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            return true;
        
        return false;
}
    string reverseVowels(string s) {
        string vowel = "";
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) vowel += s[i];
        }
        reverse(vowel.begin(), vowel.end());
        
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i] = vowel[j];
                j++;
            }
        }
        
        return s;
    }
};