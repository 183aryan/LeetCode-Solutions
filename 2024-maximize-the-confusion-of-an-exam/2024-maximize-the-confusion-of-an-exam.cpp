class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, right = 0, ans = 0, cntF = 0;
        for(right=0;right<answerKey.size();right++){
            if(answerKey[right] == 'F') cntF++;
            while(cntF > k){
                if(answerKey[left] == 'F') cntF--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        
        left = 0, right = 0;
        int cntT = 0;
        for(right=0;right<answerKey.size();right++){
            if(answerKey[right] == 'T') cntT++;
            while(cntT > k){
                if(answerKey[left] == 'T') cntT--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};