class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0;
        long maxi = 0;
        
        for(int i=0;i<target.size();i++){
            sum += target[i];
        }
        maxi = max_element(target.begin(),target.end()) - target.begin();
        
        long diffr = sum - target[maxi];
        
        if(target[maxi] == 1 || diffr == 1) return true;
        if(diffr > target[maxi] || diffr == 0 || target[maxi]%diffr == 0) return false;
        
        target[maxi] %= diffr;
        
        return isPossible(target);
    }
};