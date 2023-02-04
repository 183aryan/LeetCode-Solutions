class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        sort(s1.begin(), s1.end());
        
        for(int i=0;i<=s2.size() - s1.size();i++){
            string temp = s2.substr(i, s1.size());
            // cout << temp << endl;
            sort(temp.begin(), temp.end());
            if(s1 == temp) return true;
        }
        return false;
    }
};