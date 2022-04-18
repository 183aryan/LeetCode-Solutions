class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3) return 0;
        int ans = 0;
        for(int i=1;i<arr.size()-1;i++){
            int left = i - 1;
            int right = i + 1;
            
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){  // yaha par cnt = 1 ho jayega as ek compare ho rha h...
                while(left > 0 and arr[left-1] < arr[left]) left--;
                while(right < arr.size()-1 and arr[right+1] < arr[right]) right++;                             ans = max(ans,right-left+1);
            }
        }
        return ans;
    }
};