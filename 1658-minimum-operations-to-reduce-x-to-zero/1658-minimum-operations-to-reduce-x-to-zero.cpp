class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // sort(nums.begin(),nums.end());
        if(nums[0] > x and nums[nums.size()-1] > x) return -1;
        
        int sum = 0,sum1 = 0,cnt = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        
        if(x > sum) return -1;
        
        sum -= x;
        
        if(sum == 0) return nums.size();
        
        int i=0,j;
        for(j=0;j<nums.size();j++){
            sum1 += nums[j];
            
            while(i < nums.size() and sum1 > sum){
                sum1 -= nums[i];
                i++;
            }
            
            if(sum1 == sum) cnt = max(cnt,j-i+1);
        }
        if(cnt == 0) return -1;
        return nums.size()-cnt;
    }
};