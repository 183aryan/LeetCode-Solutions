class Solution {
public:
    vector<string> ans;
    unordered_map<string, int> um;
    
    int check(string s){
        stack<char> st;
        int i=0;
        
        while(i < s.size()){
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')'){
                if(st.empty() == false and st.top() == '(') st.pop();
                else st.push(s[i]);
            }
            i++;
        }
        return st.size();
    }
    
    void f(string s, int invalid){
        if(um[s] != 0) return;
        else um[s]++;
        
        if(invalid < 0) return;
        
        if(invalid == 0){
            if(check(s) == 0) ans.push_back(s);
            return;
        }
        
        for(int i=0;i<s.size();i++){
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            f(left+right, invalid-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int invalid = check(s);
        f(s, invalid);
        return ans;
    }
};