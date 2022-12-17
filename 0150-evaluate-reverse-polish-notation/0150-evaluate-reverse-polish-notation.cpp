class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int cnt=0;
        
        for(auto it:tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                long long int x = s.top();
                s.pop();
                long long int y = s.top();
                s.pop();
                
                // int res = 0;
                
                if(it == "+") s.push(y+x);
                if(it == "-") s.push(y-x);
                if(it == "*") s.push(y*x);
                if(it == "/") s.push(y/x);
            }
            else s.push(stoll(it));
        }
        return s.top();
    }
};