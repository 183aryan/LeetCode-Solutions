class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> um;
        um[0] = -1;
        
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            prefixSum %= k;
            
            if(um.find(prefixSum) == um.end()) um[prefixSum] = i;
            else{
                if(i - um[prefixSum] > 1) return true;
            }
        }
        return false;
    }
};