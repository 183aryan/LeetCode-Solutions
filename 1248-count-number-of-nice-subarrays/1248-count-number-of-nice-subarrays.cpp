class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int sum = 0;
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += (nums[i]%2);
            if(sum == k) cnt++;
            cnt += um[sum - k];
            um[sum]++;
        }
        return cnt;
    }
};