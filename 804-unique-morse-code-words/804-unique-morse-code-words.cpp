class Solution {
public:
    string str[26] = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."
    };
    
    string check(string st){
        string s = "";
        for(int i=0;i<st.size();i++){
            s += str[(int)(st[i] - 'a')];
        }
        return s;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        
        for(int i=0;i<words.size();i++){
            string st = check(words[i]);
            s.insert(st);
        }
        return s.size();
    }
};