class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        // ax + by = d;
        // here d = 1;
        // it is only possible when gcd(a, b) = 1;
        // so we need to check whether any pair with gcd 1 exist or not.
        // hence, we have to check whether gcd of array is it equal to one or not
        
        int gcd = 0;
        for(auto it:nums){
            gcd = __gcd(gcd, it);
        }
        return gcd == 1;
    }
};