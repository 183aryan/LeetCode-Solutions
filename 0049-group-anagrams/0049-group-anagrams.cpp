class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vvs;
        map<map<char, int>, vector<string>> mmvs;
        int n = strs.size();
        for(int i=0;i<n;i++){
            map<char, int> m;
            for(int j=0;j<strs[i].size();j++){
                m[strs[i][j]]++;
            }
            mmvs[m].push_back(strs[i]);
        }
        
        for(auto it:mmvs){
            vvs.push_back(it.second);
        }
        
        return vvs;
    }
};