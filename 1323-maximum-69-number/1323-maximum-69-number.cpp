class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        // cout << s ;
        for(int i=0;i<s.size();i++){
            if(s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        int x = stoi(s);
        cout << x ;
        return x;
    }
};