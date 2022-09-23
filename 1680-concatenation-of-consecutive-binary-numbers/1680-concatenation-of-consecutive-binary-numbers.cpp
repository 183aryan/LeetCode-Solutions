class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        long long int ans = 0;
        for(int i=1;i<=n;i++){
            int t=i;
            int cnt=0;
            while(t>0){
                t /= 2;
                cnt++;
            }
            ans = ((ans<<cnt)+i)%mod;
        }
        return ans%mod;
    }
};