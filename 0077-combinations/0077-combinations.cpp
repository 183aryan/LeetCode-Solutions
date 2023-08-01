class Solution {
public:
    void f(int idx, int k, int n, vector<int>& temp, vector<vector<int>>& v){
        if(temp.size() == k){
            v.push_back(temp);
            return;
        }
        for(int i=idx;i<n+1;i++){
            temp.push_back(i);
            f(i+1, k, n, temp, v);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> temp;
        f(1, k, n, temp, v);
        return v;
    }
};