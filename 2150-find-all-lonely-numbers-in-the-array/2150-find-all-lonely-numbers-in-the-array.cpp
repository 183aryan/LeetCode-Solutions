class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> v;
        unordered_map<int, int> um;
        
        for(auto it:nums) um[it]++;
        
        for(auto it:um){
            if(it.second == 1 and um.count(it.first-1) == 0 and um.count(it.first+1) == 0) v.push_back(it.first);
        }
        return v;
    }
};