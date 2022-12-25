class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> v;
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++) nums[i] += nums[i-1];
        
        for(int i=0;i<queries.size();i++){
            int sum = 0, j;
            for(j=0;j<nums.size();j++){
                if(nums[j] > queries[i]) break;
            }
            v.push_back(j);
        }
        return v;
    }
};