class Solution {
public:
    int f(int i, int prev, vector<int>& arr1, vector<int>& arr2, map<pair<int, int>, int>& dp){
        if(i >= arr1.size()) return 0;
        
        if(dp.find({i, prev}) != dp.end()) return dp[{i, prev}];
        
        int ans = INT_MAX;
        
        int id = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        
        if(arr1[i] > prev) ans = min(ans, f(i+1, arr1[i], arr1, arr2, dp));
        if(id < arr2.size()) ans = min(1LL*ans, 1LL*f(i+1, arr2[id], arr1, arr2, dp)+1);
        
        return dp[{i, prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int res = f(0, INT_MIN, arr1, arr2, dp);
        
        return res >= INT_MAX ? -1 : res; 
    }
};