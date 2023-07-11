class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int maxi = 0;
        int curr = 0;
        int i=0, j=0;
        while(j < s.size()){
            um[s[j]]++;
            
            if(um[s[j]] > 1){
                while(um[s[j]] > 1){
                    um[s[i]]--;
                    if(um[s[i]] == 0) um.erase(s[i]);
                    i++;
                }
            }
            else maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
    //     vector<int> v(256, 0);
    //     int i=0, j=0;
    //     int maxi = 0;
    //     while(j < s.size()){
    //         v[s[j]]++;
    //         while(v[s[j]] > 1){
    //             v[s[i++]]--;
    //         }
    //         maxi = max(maxi, j-i+1);
    //         j++;
    //     }
    //     return maxi;
    // }
};