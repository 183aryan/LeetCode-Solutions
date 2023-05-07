class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int> lis;
        vector<int> v(obs.size(), 1);
        lis.push_back(obs[0]);
        
        for(int i=1;i<obs.size();i++){
            if(lis.back() <= obs[i]){
                lis.push_back(obs[i]);
                v[i] = lis.size();
            }
            else{
                int index = upper_bound(lis.begin(), lis.end(), obs[i]) - lis.begin();
                lis[index] = obs[i];
                v[i] = index + 1;
            }
        }
        return v;
    }
};