class Solution {
public:
    bool check(int mid, vector<int>& piles, int h){
        long long int cnt=0;
        for(int i=0;i<piles.size();i++){
            cnt += ceil(1.0*piles[i]/mid);
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1,hi=1e9,mid; 
        int ans;
        while(hi >= lo){
            mid = lo + (hi - lo)/2;
            if(check(mid, piles, h)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};