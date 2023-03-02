class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt;
        string s;
        
        for(int i=0;i<chars.size();i++){
            cnt=1;
            while(i < chars.size() -1 and chars[i] == chars[i+1]){
                i++;
                cnt++;
            }
            s += chars[i];
            if(cnt == 1) continue;
            s += to_string(cnt);
        }
        
        // vector<char> v;
        chars.clear();
        for(auto it:s) chars.push_back(it);
        // return v.size();
        // cout << s << endl;
        return chars.size();
    }
};