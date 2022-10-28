class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vvs;
        unordered_map<string, vector<string>> msvs;
        
        int n = strs.size();
        
        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            
            msvs[temp].push_back(strs[i]);
        }
        
        for(auto it:msvs){
            vvs.push_back(it.second);
        }
        return vvs;
    }
};