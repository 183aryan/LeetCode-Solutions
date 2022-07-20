class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> m;
        int i=0;
        for(auto x:s){
            m[x].push_back(i);
            i++;
        }
        
        int cnt = 0;
        
        for(int i=0;i<words.size();i++){
            string curr = words[i];
            int lru = -1;
            for(int j=0;j<curr.size();j++){
                auto it = upper_bound(m[curr[j]].begin(),m[curr[j]].end(),lru);
                if(it == m[curr[j]].end()) break;
                lru = *it;
                
                if(j == curr.size()-1) cnt++;
            }
        }
        return cnt;
    }
};