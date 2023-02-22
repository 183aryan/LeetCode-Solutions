class Solution {
public:
    bool check(int mid, vector<int>& weights, int days){
        int cnt=1;
        int ans=0;
        bool flag = true;
        for(auto it:weights){
            if(it > mid) flag = false;
            if(ans + it <= mid) ans += it;
            else{
                cnt++;
                ans = it;
            }
        }
        if(flag == false) return false;
        
        return (cnt <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=0, hi=10000000, mid;
        int ans;
        while(hi >= lo){
            mid = lo + (hi - lo)/2;
            
            if(check(mid, weights, days)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;       
    }
};