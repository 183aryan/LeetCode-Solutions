class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        
        vector<pair<int, char>> vpii;
        
        for(auto it:m){
            if(it.second > 0){
                // cout << it.second << " " << it.first << endl;
                vpii.push_back({it.second, it.first});
            }
        }
        
        sort(vpii.begin(), vpii.end(), greater());
        
        // for(auto it:vpii){
        //     cout << it.first << " " << it.second << endl;
        // }
        
        string s1 = "";
        
        for(auto it:vpii){
            for(int i=0;i<it.first;i++) s1 += it.second;
        }
        
        return s1;
    }
};