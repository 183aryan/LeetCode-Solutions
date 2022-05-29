class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> m;
        for(auto it:wordList)
            m[it]++;
        
        if(m.find(endWord)==m.end())
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int ans=1;
        while(!q.empty()) 
        {
            int n=q.size();
            for(int i=0;i<n;i++) 
            {
                string x=q.front();
                q.pop();
                
                if(x==endWord) 
                    return ans;
                
                m.erase(x);
                for(int j=0;j<x.size();j++) 
                {
                    char c=x[j];
                    for(char k='a';k<='z';k++) 
                    {
                        if(k==c)
                            continue;
                        x[j]=k;
                        if(m.find(x) != m.end()) 
                            q.push(x);
                     }
                     x[j]=c;
                }
            }
            ans++;
        }
        return 0;
    }
};