class Solution {
public:
    vector<int> check(string pattern){
         if(pattern.size() == 0)
            return {};
        
         vector<int> v;
         int ind = 0;
		
         unordered_map<char,int> um;
         for(int i = 0; i<pattern.size(); ++i)
         {
            if(um.find(pattern[i]) == um.end())
            {
               um.insert({pattern[i],ind++});
               v.push_back(um[pattern[i]]);
            }
            else
            {
                v.push_back(um[pattern[i]]);
            }
         }
         return v;
     }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> v = check(pattern);
        
        int n = words.size();
        vector<string> ans;
        
        for(int i = 0; i<n; ++i)
        {
            vector<int> ptrn = check(words[i]);
            
            if(v == ptrn)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};