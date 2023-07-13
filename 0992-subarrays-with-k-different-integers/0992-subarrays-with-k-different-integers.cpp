class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int, int> um;
        int i=0, j=0;
        int cnt = 0;
        
        while(j < nums.size()){
            um[nums[j]]++;
            
            while(um.size() > k){
                um[nums[i]]--;
                if(um[nums[i]] == 0) um.erase(nums[i]);
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};