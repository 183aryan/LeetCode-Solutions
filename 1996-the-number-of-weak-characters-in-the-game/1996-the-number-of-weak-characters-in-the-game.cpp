class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] != b[0]) return a[0] > b[0];
        return a[1] < b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int cnt=0, maxi = INT_MIN;
        sort(properties.begin(), properties.end(),cmp);
        for(int i=0;i<properties.size();i++){
            if(properties[i][1] < maxi) cnt++;
            else maxi = properties[i][1];
        }
        return cnt;
    }
};