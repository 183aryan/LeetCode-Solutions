class Solution {
public:
    int isVowel(char ch){
        if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u'){
            return 1;
        }
        return 0;
    }
    int maxVowels(string s, int k) {
        int maxi = INT_MIN;
        int curr = 0;
        
        for(int i=0;i<s.size();i++){
            curr += isVowel(s[i]);
            if(i >= k){
                curr -= isVowel(s[i-k]);
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};