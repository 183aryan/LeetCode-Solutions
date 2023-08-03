class Solution {
public:
    void f(int idx, string digits, string s, vector<string>& vs, unordered_map<char, string>& um){
        if(idx == digits.size()){
            vs.push_back(s);
            return;
        }
        
        if(digits[idx] != '7' and digits[idx] != '9'){
            for(int i=0;i<3;i++){
                s += um[digits[idx]][i];
                f(idx+1, digits, s, vs, um);
                s.pop_back();
            }
        }
        else{
            for(int i=0;i<4;i++){
                s += um[digits[idx]][i];
                f(idx+1, digits, s, vs, um);
                s.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string s = "";
        vector<string> vs;
        unordered_map<char,string> um;
        um['2']="abc";
        um['3']="def";
        um['4']="ghi";
        um['5']="jkl";
        um['6']="mno";
        um['7']="pqrs";
        um['8']="tuv";
        um['9']="wxyz";
        f(0, digits, s, vs, um);
        return vs;
    }
};