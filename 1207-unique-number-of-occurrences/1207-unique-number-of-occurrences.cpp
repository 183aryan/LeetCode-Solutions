class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int i=0;i<arr.size();i++){
            um[arr[i]]++;
        }
        
        set<int> s;
        
        for(auto it:um){
            s.insert(it.second);
        }
        
        if(s.size() == um.size()) return true;
        
        return false;
    }
};