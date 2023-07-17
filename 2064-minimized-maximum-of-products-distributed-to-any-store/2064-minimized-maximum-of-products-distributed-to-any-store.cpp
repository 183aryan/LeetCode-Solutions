class Solution {
public:
    bool check(int x, int n, vector<int>& q){
        long long int cnt=0;
        for(int i=0;i<q.size();i++){
            cnt += ceil(1.0*q[i] / x);
        }
        return (cnt <= n);
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        while(hi >= lo){
            long long int mid = lo + (hi - lo) / 2;
            if(check(mid, n, quantities)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};