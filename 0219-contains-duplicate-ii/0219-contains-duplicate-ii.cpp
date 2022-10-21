class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // int diff=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j] && abs(i-j)<=k)
        //             return true;
        //     }
        // }
        // return false;
        vector<pair<int,int>> vp;
        
        for(int i=0;i<nums.size();i++){
            vp.push_back(make_pair(nums[i],i));
        }
        sort(vp.begin(),vp.end());
        
        for(int i=1;i<vp.size();i++){
            if(vp[i].first == vp[i-1].first && abs(vp[i].second-vp[i-1].second)<=k)
                return true;
        }
        return false;
    }
};