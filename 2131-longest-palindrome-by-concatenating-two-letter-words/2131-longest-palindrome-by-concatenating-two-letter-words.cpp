class Solution {
public:
    int longestPalindrome(vector<string>& words) {
//         unordered_map<string, int> um;
//         for(int i=0;i<words.size();i++){
//             um[words[i]]++;
//         }
        
//         bool flag = false;
//         for(auto it:um){
//             string s = it.first;
//             string t = s;
//             reverse(t.begin(), t.end());
//             if(s == t){
//                 if(it.second%2) flag = true;
//             }
//             else{
//                 if(um.find(t) != um.end()){
//                     ans += min(it.second, um[t]);
//                     um.erase(t);
//                 }
//             }
//         
        vector<vector<int>> check(26, vector<int> (26,0));
        int cnt = 0;
        
        for(auto it:words){
            int first = it[0] - 'a';
            int second = it[1] - 'a';
            // cout << first <<" "<< second;
            
            if(check[second][first]){
                cnt += 4;
                check[second][first]--;
            }
            else check[first][second]++;
        }
        
        for(int i=0;i<26;i++){
            if(check[i][i]){
                cnt += 2;
                break;
            }
        }
        return cnt;
    }
};