class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v;
        unordered_map<int, int> um;
        
        for(auto it:nums){
            um[it]++;
            if(um[it] > 1){
                v.push_back(it);
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(um[i] == 0){
                v.push_back(i);
                break;
            }
        }
        return v;
    }
};