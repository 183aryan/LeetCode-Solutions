class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        
        int maxSum = 0;
        int sum = 0;
            
        for(int i=0;i<satisfaction.size();i++){
            sum += satisfaction[i];
            maxSum = max(maxSum, maxSum+sum);
        }
        return maxSum;
    }
};