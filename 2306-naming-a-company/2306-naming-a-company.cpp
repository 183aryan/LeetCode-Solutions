class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> vs(26);
        
        for(int i=0;i<ideas.size();i++){
            vs[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
        }
        
        long long int cnt=0;
        
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long long int common=0;
                for(auto x:vs[i]){
                    if(vs[j].count(x)) common++;
                }
                cnt += (2 * (vs[i].size() - common) * (vs[j].size() - common));
            }
        }
        return cnt;
    }
};