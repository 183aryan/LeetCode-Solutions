class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
        unordered_map<int, int> um;
        int cnt = 0;
        
        for(auto it1:nums1){
            for(auto it2:nums2){
                um[it1+it2]++;
            }
        }
        
        for(auto it1:nums3){
            for(auto it2:nums4){
                if(um.count(0-(it1+it2))) cnt += um[-(it1+it2)];
            }
        }
        
        return cnt;
    }
};