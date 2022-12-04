class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int tot_sum=0;
        for(int i=0;i<nums.size();i++) tot_sum += nums[i];
        long long int n = nums.size();
        long long int minDiff = INT_MAX;
        long long int sum=0;
        long long int avg1,avg2,ind;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            tot_sum -= nums[i];
            
            avg1 = sum/(i+1);
            if(i == n-1){
                avg2 = 0;
            }else avg2 = tot_sum/(n-i-1);
            
            if(minDiff > abs(avg1-avg2)){
                minDiff = abs(avg1-avg2);
                ind = i;
            }
        }
        return ind;
    }
};