class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;
        
        for(int i=0;i<rocks.size();i++){
            diff.push_back(capacity[i] - rocks[i]);
        }
        
        int cnt=0;
        sort(diff.begin(), diff.end());
        
        for(int i=0;i<diff.size();i++){
            if(diff[i] > 0 and additionalRocks >= diff[i]){
                additionalRocks -= diff[i];
                diff[i] = 0;
            }
        }
        
        for(int i=0;i<diff.size();i++){
            if(diff[i] == 0) cnt++;
        }
        
        return cnt;
    }
};