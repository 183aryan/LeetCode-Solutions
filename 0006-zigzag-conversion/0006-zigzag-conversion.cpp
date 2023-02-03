class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int n=s.size();
        int i=0;
        while(i < n){
            for(int j=0;j<numRows and i<n;j++){
                v[j].push_back(s[i]);
                i++;
            }
            for(int j=numRows-2;j>0 and i<n;j--){
                v[j].push_back(s[i]);
                i++;
            }
        }
        string ans;
        for(int i=0;i<v.size();i++) ans += v[i];
        
        return ans;
    }
};