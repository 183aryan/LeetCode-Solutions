class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int cnt = 0;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() == false and s[i] == ')' || s[i] == '('){
                st.push(s[i]);
                if(s[i] == '('){
                    cnt++;
                    maxi = max(maxi, cnt);
                }
                else cnt--;
            }
        }
        return maxi;
    }
};