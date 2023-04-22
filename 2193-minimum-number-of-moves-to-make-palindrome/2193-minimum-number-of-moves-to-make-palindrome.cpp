class Solution {
public:
    int find(string &s, int lo, int t){
        while(t > lo){
            if(s[t] == s[lo]) return t;
            t--;
        }
        return t;
    }
    int minMovesToMakePalindrome(string s) {
        int lo=0, hi=s.size()-1;
        int cnt=0;
        
        while(lo < hi){
            if(s[lo] == s[hi]){
                lo++;
                hi--;
            }
            else{
                int t = hi;
                t = find(s, lo, t);
                
                if(t == lo){
                    swap(s[t], s[t+1]);
                    cnt++;
                }
                else{
                  while(t < hi){
                      swap(s[t], s[t+1]);
                      cnt++;
                      t++;
                  }  
                  lo++;
                  hi--;
                }
            }
        }
        return cnt;
    }
};
