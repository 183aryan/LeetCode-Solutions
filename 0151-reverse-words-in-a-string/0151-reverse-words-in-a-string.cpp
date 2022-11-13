class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> st;
        for(int i=0;i<s.size();i++){
            string s1;
            if(s[i] == ' ') continue;
            while(s[i] != ' ' and i < s.size()){
                s1 += s[i];
                i++;
            }
            st.push(s1);
        }
    
        string s2;
        while(st.empty() == false){
            s2 += st.top();
            st.pop();
            if(!st.empty()) s2 += " ";
        }
        
        return s2;
    }
};