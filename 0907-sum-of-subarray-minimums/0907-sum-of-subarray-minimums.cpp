class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left, right;
        stack<int> s;
        
        
        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()) left.push_back(-1);
            else left.push_back(s.top());
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()] > arr[i]){
                s.pop();
            }
            if(s.empty()) right.push_back(n);
            else right.push_back(s.top());
            s.push(i);
        }
        
        reverse(right.begin(), right.end());
        long long int res=0;
        
        for(int i=0;i<n;i++){
            long long int x = i-(left[i]+1) + right[i]-1-i+1;
            long long int y = (long long)(i-(left[i]+1))*(long long)(right[i]-1-i);
            
            x+=y;
            
            res += (arr[i]*x)%mod;
            res %= mod;
        }
        return res;
    }
};