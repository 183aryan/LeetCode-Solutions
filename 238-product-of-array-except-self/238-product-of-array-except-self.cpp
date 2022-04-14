class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> v;
//         int product = 1;
//         for(int i=0;i<nums.size();i++){
//             product *= nums[i];
//         }
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] == 0){
//                 v.push_back()
//             }
//             else v.push_back(product/nums[i]);
//         }
//         return v;
        vector<int> v;
        int n = nums.size();
        int left[n],right[n];
        int prodL = 1, prodR = 1;
        
        left[0] = 1;
        for(int i=1;i<n;i++){
            prodL = prodL * nums[i-1];
            left[i] = prodL;
        }
        
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            prodR = prodR*nums[i+1];
            right[i] = prodR;
        }
        
        for(int i=0;i<n;i++){
            v.push_back(left[i]*right[i]);
        }
        
        return v;
    }
};