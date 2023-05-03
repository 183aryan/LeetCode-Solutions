class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // set<int> s1,s2;
        // for(int i=0;i<nums1.size();i++){
        //     s1.insert(nums1[i]);
        // }
        // for(int i=0;i<nums2.size();i++){
        //     s2.insert(nums2[i]);
        // }
        // vector<vector<int>> vv;
        // vector<int> row;
        // for(auto &x:s1){
        //     if(s2.find(x) == s2.end()) row.push_back(x);
        // }
        // vv.push_back(row);
        // row.clear();
        // for(auto &x:s2){
        //     if(s1.find(x) == s1.end()) row.push_back(x);
        // }
        // vv.push_back(row);
        // return vv;
        
        // code below is very new approach........do try to learn it........
        vector<int> v1,v2;
        set<int> s1(nums1.begin(),nums1.end()), s2(nums2.begin(),nums2.end());
        set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(v1));                       set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),back_inserter(v2));
        return {v1,v2};
    }
};