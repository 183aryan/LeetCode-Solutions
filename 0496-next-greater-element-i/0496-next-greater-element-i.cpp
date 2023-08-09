class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        stack<int> s;
        vector<int> v;
        
        for(auto it:nums2){
            while(s.size() and s.top() < it){
                um[s.top()] = it;
                s.pop();
            }
            s.push(it);
        }
        for(auto it:nums1){
            v.push_back(um.count(it) ? um[it]:-1);
        }
        return v;
    }
};