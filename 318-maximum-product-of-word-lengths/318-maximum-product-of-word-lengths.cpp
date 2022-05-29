class Solution {
public:
    bool check(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s1[i] == s2[j]) return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int mx = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(mx >=  words[i].length() * words[j].length()) continue;
                if(check(words[i],words[j])){
                    int val = words[i].length() * words[j].length();
                    mx = max(val,mx);
                }    
            }
        }
        return mx;
    }
};