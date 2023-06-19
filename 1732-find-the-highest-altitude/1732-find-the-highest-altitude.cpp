class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> v(gain.size()+1);
        v.push_back(0);
        for(int i=0;i<gain.size();i++){
            v.push_back(gain[i]+v.back());
        }
        return *max_element(v.begin(), v.end());
    }
};