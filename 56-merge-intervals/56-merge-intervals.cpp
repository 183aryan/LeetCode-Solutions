class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // vector<vector<int>> v;
        // if(intervals.size() == 0) return v;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans{intervals[0]};
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>ans.back()[1]) // intervals can't be merged
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1],intervals[i][1]); // intervals can be merged
        }       
        return ans;
    }
};