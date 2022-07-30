class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> temp(26,0);
        for(auto w:words2)
        {
            vector<int> ch(26,0);
            for(auto c:w)
            {
                ch[c-'a']++;
                temp[c-'a']=max(temp[c-'a'],ch[c-'a']);
            }
        }
        vector<string> ans;
        for(auto word:words1)
        {
           vector<int> temp2(26,0);
            for(char ch:word)
            {
                temp2[ch-'a']++;
            }
            bool flag=true;
            for(int i=0;i<26;i++)
            {
                if(temp[i]<=temp2[i])
                {
                    continue;
                }
                else {
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(word);
        }
        return ans;
        
    }
};