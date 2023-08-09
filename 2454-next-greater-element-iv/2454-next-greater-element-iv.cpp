class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        stack<int> s1, s2, temp;
        vector<int> v(n, -1);
        
        for(int i=0;i<n;i++){
            while(s2.size() and nums[s2.top()] < nums[i]){
                v[s2.top()] = nums[i];
                s2.pop();
            }
            while(s1.size() and nums[s1.top()] < nums[i]){
                temp.push(s1.top());
                s1.pop();
            }
            while(temp.size()){
                s2.push(temp.top());
                temp.pop();
            }
            s1.push(i);
        }
        return v;
    }
};