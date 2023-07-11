class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //     unordered_map<char, int> um;
    //     int maxi = 0;
    //     int curr = 0;
    //     int i=0, j=0;
    //     while(j < s.size()){
    //         if(um[s[j]] == 0){
    //             curr++;
    //             maxi = max(maxi, j-i+1);
    //             um[s[j]]++;
    //             j++;
    //         }
    //         else {
    //             curr = 0;
    //             i=j;
    //         }
    //     }
    //     return maxi;
    // }
        vector<int> v(256, 0);
        int i=0, j=0;
        int maxi = 0;
        while(j < s.size()){
            v[s[j]]++;
            while(v[s[j]] > 1){
                v[s[i++]]--;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};