class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int ans = 0;
        int i = 0, j = tokens.size()-1;
        int n = tokens.size();
        while(i<=j){
            while(i<=j && tokens[i]<=power){
                ans++;
                power -= tokens[i];
                i++;
            }
            if(i>=j || ans<=0) break;
            ans -= 1;
            power += tokens[j];
            j--;
            
        }
        return ans;
    }
};