class Solution {
public:
    int mx = 0, ans = 0;
    int check(int x){
        return x;
    }
    int minPartitions(string n) {
        for(int i=0;i<n.size();i++){
            int x = n[i]-'0';
            ans = check(x);
            mx = max(ans,mx);
        }
        return mx;
    }
};