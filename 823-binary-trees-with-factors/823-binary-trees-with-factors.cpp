// int mod = 1e9 + 7;
class Solution {
public:
    unordered_set<int> us;
    unordered_map<int,long long> um;
    
    long long f(int root){
        if(um.count(root)) return um[root];
        
        long long cnt = 1;
        for(int x:us){
            if(root%x == 0 and us.count(root/x)){
                cnt += f(x) * f(root/x);
            }
        }
        return um[root] = cnt;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        us.insert(arr.begin(),arr.end());
        
        long long ans = 0;
        for(int x:us){
            ans += f(x);
        }
        return int(ans%1000000007);
    }
};