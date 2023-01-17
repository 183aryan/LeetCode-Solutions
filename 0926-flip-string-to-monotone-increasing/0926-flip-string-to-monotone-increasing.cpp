class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one=0;
        int to_flip=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '1') one++;
            else to_flip++;
            
            to_flip = min(to_flip, one);
        }
        return to_flip;
    }
};