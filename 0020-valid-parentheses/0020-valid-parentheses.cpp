class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char,int> m;
        m.insert({'(',-1});
        m.insert({')',1});
        m.insert({'[',-2});
        m.insert({']',2});
        m.insert({'{',-3});
        m.insert({'}',3});
        
        
        stack<char> st;
        
        for(char br:s){
            if(m[br]<0){
                st.push(br);
            }
            else{
                if(st.empty()) return false;
                
                char t = st.top();
                st.pop();
                if(m[t] + m[br] != 0) return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};