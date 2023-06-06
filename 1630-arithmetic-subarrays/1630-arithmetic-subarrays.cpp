class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> v;
        
        for(int i=0;i<r.size();i++){
            vector<int> v1(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(v1.begin(), v1.end());
            
            if(nums.size() == 1){
                v.push_back(false);
                continue;
            }
            
            int diff = v1[1] - v1[0];
            bool flag = true;
            
            for(int j=2;j<v1.size();j++){
                if((v1[j] - v1[j-1]) != diff){
                    flag = false;
                    break;
                }
            }
            v.push_back(flag);
        }
        return v;
    }
};