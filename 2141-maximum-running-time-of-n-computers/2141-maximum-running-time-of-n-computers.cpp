class Solution {
public:
    bool check(long long int x, int n, vector<int>& arr){
        long long int total = 0;
        for(long long int it:arr){
            if(x > it) total += it;
            else total += x;
        }
        return total >= n*x;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long int lo = 0, hi = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long int ans;
        
        while(hi >= lo){
            long long int mid = lo + (hi - lo) / 2;
            if(check(mid, n, batteries)){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};