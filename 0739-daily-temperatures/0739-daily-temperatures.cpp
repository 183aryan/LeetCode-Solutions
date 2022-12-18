class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size(),0);
        stack<int> s;
        for(int i=0;i<temperatures.size();i++){
            while(!s.empty() and temperatures[s.top()] < temperatures[i]){
                v[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return v;
    }
};