class Solution {
public:
     bool okk(vector<int>& dist,double hour, int mid){
        double time = 0;
        for(int i=0;i<dist.size();i++){
            time = ceil(time);
            time += (double)(dist[i])/(mid);
        }
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo=1;
        int hi=1e7, mid;
        if(dist.size()-1>=hour) return -1;
        int ans;
        while(hi>=lo){
            mid = lo + (hi-lo)/2;
            if(okk(dist, hour, mid)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};