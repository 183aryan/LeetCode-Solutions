class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> um;
        int ans=0;
        int i=0, j=0;
        for(j=0;j<fruits.size();j++){
            um[fruits[j]]++;
            if(um.size() > 2){
                um[fruits[i]]--;
                if(um[fruits[i]] == 0) um.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};