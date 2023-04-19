class Solution {
public:
    long long appealSum(string s) {
        vector<long long> v(26, 0);
        
        long long int ans=0;
        long long int temp=0;
        for(int i=0;i<s.size();i++){
            temp += i+1 - v[s[i] - 'a'];
            v[s[i] - 'a'] = i+1;
            ans += temp;
        }
        
        return ans;
    }
};