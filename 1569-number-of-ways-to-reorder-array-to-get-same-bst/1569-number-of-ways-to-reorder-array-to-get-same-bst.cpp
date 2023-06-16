class Solution {
public:
    long long int mod = 1e9+7;
    
    vector<vector<long long int>> table;
    
    long long int f(vector<int>& nums){
        if(nums.size() <= 2) return 1;
        
        vector<int> left, right;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long int left_res = f(left)%mod;
        long long int right_res = f(right)%mod;
        
        return (((table[nums.size() - 1][left.size()] * left_res) % mod) * right_res) % mod;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        table.resize(n+1);
        for(int i = 0; i < n + 1; ++i){
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        
        long long int res = f(nums);
        return res%mod - 1;
    }
};