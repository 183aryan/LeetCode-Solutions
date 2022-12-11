//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
       unordered_map<int, int> um;
       for(int i=0;i<nums.size();i++){
           um[nums[i]%k]++;
           nums[i] %= k;
       }
       for(auto it:nums){
           if(um[it] > 0  and um[(k-it)%k] > 0){
               um[it]--;
               um[(k-it)%k]--;
           }
          else if(um[it] > 0 || um[it] < 0) return false;
       }
       return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends