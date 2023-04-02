class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        
        sort(potions.begin(), potions.end());
        for(int i=0;i<spells.size();i++){
            long long int lo=0, hi=potions.size()-1, mid;
            int ans=-1;
            while(hi >= lo){
                mid = lo + (hi- lo)/2;
                
                if(1LL*spells[i]*potions[mid] >= success){
                    hi = mid-1;
                    ans = mid;
                }
                else{
                    lo = mid+1;
                }
            }
            
            if(ans == -1) v.push_back(0);
            else v.push_back(potions.size() - ans);
        }
        return v;
    }
};