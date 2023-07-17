class Solution {
public:
    bool check(int x, int m, int k, vector<int>& v){
        int cnt=0;
        int tot=0;
        
        for(int i=0;i<v.size();i++){
            if(v[i] <= x) cnt++;
            else cnt=0;
            
            if(cnt == k) {
                tot++;
                cnt=0;
            }
        }
        return (tot>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo=1, hi=*max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(hi>=lo){
            int mid = lo + (hi - lo) / 2;
            if(check(mid, m, k, bloomDay)){
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