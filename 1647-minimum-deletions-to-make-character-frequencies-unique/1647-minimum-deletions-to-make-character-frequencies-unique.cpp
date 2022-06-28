class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        
        set<int> st;
        int res = 0;
        
        for(auto[i,j] : m){
            while(st.find(j) != st.end()){
                j--;
                res++;
            }
            
            if(j>0) st.insert(j);
        }
        return res;
    }
};