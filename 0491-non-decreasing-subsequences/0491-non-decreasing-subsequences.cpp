class Solution {
public:
     void solve(int i, int n, vector<int>& nums, set<vector<int>> &s,vector<int> &t){
        if(t.size()>=2){
            s.insert(t);
        }

        for(int j = i;j<n;j++){
            if(t.size()==0){
                t.push_back(nums[j]);
                solve(j+1,n,nums,s,t);
                t.pop_back();
                continue;
            }

            int k = t[t.size()-1];

            if(k<=nums[j]){
                t.push_back(nums[j]);
                solve(j+1,n,nums,s,t);
                t.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();

        int i,j;

        vector<vector<int>> res;
        set<vector<int>> s;
        vector<int> t;
        for(i=0;i<n;i++){
            solve(i,n,nums,s,t);
        }

        for(auto a:s){
            res.push_back(a);
        }

        return res;  
    }
};