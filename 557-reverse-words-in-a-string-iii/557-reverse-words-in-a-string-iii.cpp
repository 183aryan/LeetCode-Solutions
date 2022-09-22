class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        int j=0,k=0;
        for(int i=0;i<=s.size();i++){
            if(i == s.size()-1){
                reverse(s.begin()+j,s.end());
            }
            else if(s[i] != ' ') k++;
            else{
                reverse(s.begin()+j,s.begin()+k);
                // cout << s << endl;
                j = k + 1;
                k++;
            }
        }
        return s;
    }
};