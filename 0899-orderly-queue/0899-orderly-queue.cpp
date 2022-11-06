class Solution {
public:
    void rotate(string& s){
        char c = s[0];
        for(int i=0;i<s.size()-1;i++) s[i] = s[i+1];
        s[s.size() - 1] = c;
    }
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        string temp = s;
        for(int i=0;i<s.size();i++){
            rotate(temp);
            if(s > temp){
                s = temp;
            }
        }
        return s;
    }
};