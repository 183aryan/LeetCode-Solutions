class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> um;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) arr[i] = -1;
        }
        
        int preSum = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            preSum += arr[i];
            if(preSum == 0){
                res = max(res, i+1);
            }
            if(um.find(preSum) != um.end()){
                res = max(res, i - um[preSum]);
            }
            if(um.find(preSum) == um.end()) um[preSum] = i;
        }
        return res;
    }
};