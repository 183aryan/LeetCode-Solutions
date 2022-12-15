class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long int cnt=0;
        long long int ans1=0, ans2=0;
        
        string first = pattern[0] + text;
        string second = text + pattern[1];
        
        for(int i=0;i<first.size();i++){
            if(first[i] == pattern[0]) cnt++;
            else if(first[i] == pattern[1]) ans1 += cnt;
        }
        if(pattern[0] == pattern[1]) ans1 = (cnt*(cnt-1))/2;
        
        cnt = 0;
        for(int i=second.size();i>=0;i--){
            if(second[i] == pattern[1]) cnt++;
            else if(second[i] == pattern[0]) ans2 += cnt;
        }
        if(pattern[0] == pattern[1]) ans2 = (cnt*(cnt-1))/2;
        
        return max(ans1, ans2);
    }
};