class Solution {
public:
    int check(string s){
        int cnt = 0;
        for(auto &x:s){
            if(x == ' ') cnt++;
        }
        return cnt+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> um;
        for(int i=0;i<senders.size();i++){
            int res = check(messages[i]);
            um[senders[i]] += res;
        }
        
        int mx = INT_MIN;
        string mxS;
        for(auto &x:um){
            if(x.second > mx){
                mx = x.second;
                mxS = x.first;
            }
            else if(x.second == mx and x.first > mxS) mxS = x.first;
        }
        return mxS;  
    }
};