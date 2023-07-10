class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
//         unordered_map<int, int> um;
//         int sum = 0;
//         int cnt = 0;
        
//         for(int i=0;i<nums.size();i++){
//             sum += (nums[i]%2);
//             if(sum == k) cnt++;
//             cnt += um[sum - k];
//             um[sum]++;
//         }
//         return cnt;
        
        // TWO POINTER APPROACH
        int l=0, r=0;
        int cnt = 0;
        int tot = 0;
        int odd = 0;
        
        while(r < nums.size()){
            if(nums[r]%2 != 0){
                odd++;
                cnt = 0;
            }
            while(odd == k){
                cnt++;
                odd -= (nums[l]&1);
                l++;
            }
            tot += cnt;
            r++;
        }
        return tot;
    }
};