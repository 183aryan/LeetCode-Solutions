class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        sort(changed.begin(),changed.end());
        map<int, int> m;
        vector<int> v;
        for(int i=0;i<n;i++){
            m[changed[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m[changed[i]] and m[2*changed[i]]){
                m[changed[i]]--;
                m[2*changed[i]]--;
                v.push_back(changed[i]);
            }
        }
        for(auto it:m){
            if(it.second) return {};
        }
        return v;
    }
};