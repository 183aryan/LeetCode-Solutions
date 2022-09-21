class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int esum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) esum += nums[i];
        }
        vector<int> v;
        for(int i=0;i<queries.size();i++){
            if(nums[queries[i][1]]%2 == 0){
                esum -= nums[queries[i][1]];
            }
            nums[queries[i][1]] += queries[i][0];
            
            if(nums[queries[i][1]]%2 == 0){
                esum += nums[queries[i][1]];
            }
            
            v.push_back(esum);
        }
        return v;
    }
};