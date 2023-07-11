class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    long long countVowels(string word) {
        long long int cnt = 0;
        for(int i=0;i<word.size();i++){
            if(isVowel(word[i])){
                cnt += (1LL*(i+1)*(word.size()-i));
            }
        }
        return cnt;
    }
};