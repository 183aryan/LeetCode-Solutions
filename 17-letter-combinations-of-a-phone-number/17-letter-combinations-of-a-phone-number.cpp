class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits.empty()) return {};
        
        queue<string> q;
        q.push("");
        vector<string> v;
        
        while(!q.empty()){
            string x = q.front();
            q.pop();
            
            if(x.size() == digits.size()) v.push_back(x);
            else{
                string temp = phone[digits[x.size()] - '0'];
                for(auto i : temp)
                    q.push(x + i);
            }
        }
        return v;
    }
};