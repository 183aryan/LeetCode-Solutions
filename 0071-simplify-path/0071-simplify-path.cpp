class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string s;
        
        for(int i=0;i<path.size();){
            string temp="";
            while(i<path.size() and path[i] != '/'){
                temp += path[i++];
            }
            
            if(temp.empty() or temp == "."){
                i++;
                continue;
            }
            else if(temp == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(temp);
            
            i++;
        } 
        
        if(st.empty()) return "/";
        while(st.empty() == false){
            s = "/"+st.top()+s;
            st.pop();
        }
        return s;
    }
};