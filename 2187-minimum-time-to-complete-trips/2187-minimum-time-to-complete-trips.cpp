class Solution {
public:
    bool check(long long int mid, vector<int>& time, int totalTrips){
        long long int sum=0;
        for(auto i:time){
            sum += (mid/i);
        }
        return sum >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // sort(time.begin(), time.end());
        
//         vector<int> v(time.size(), 0);
        
//         for(long long int i=1;;i++){
//             long long int cnt=0;
//             for(long long int j=0;j<time.size();j++){
//                 cnt += (i/time[j]);
//             }
//             if(cnt >= totalTrips) return i;
//         }
        
        long long int lo=1, hi=1e14+5;
        long long int ans;
        
        while(hi >= lo){
            long long int mid = lo + (hi - lo)/2;
            
            if(check(mid, time, totalTrips)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};