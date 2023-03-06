class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int prev=0;
        int curr=0;
        long long int sum=0;
        sort(nums.begin(), nums.end());
        
        // int cnt;
        for(int i=0;i<nums.size();i++){
            curr = nums[i];
            
            long long int cnt = (nums[i] - prev - 1);
            
            if(cnt <= 0){
                prev = curr;
                continue;
            }
            if(cnt > k){
                cnt = k;
                curr = prev+k+1;
            }
            sum += (1LL*cnt*(curr+prev))/2;
            
            prev = curr;
            k -= cnt;
            
            if(k == 0) break;
        }
        if(k) sum += (1LL*k*(2*prev + k+1))/2;
        
        return sum;
    }
};