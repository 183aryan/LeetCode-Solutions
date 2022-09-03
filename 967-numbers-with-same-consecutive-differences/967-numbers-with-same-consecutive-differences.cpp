class Solution {
public:
    int count(int x){
        int cnt = 0;
        while(x != 0){
            x = x/10;
            cnt++;
        }
        return cnt;
    }
    void check(int curr,int n,int k,vector<int>& v){
        if(count(curr) == n){
            v.push_back(curr);
            return;
        }
        for(int i=0;i<10;i++){
            int prev = curr%10;
            if(abs(prev-i) == k){
                check(curr*10+i,n,k,v);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> v;
        if(n == 1){
            v.push_back(0);;
        }
        
        for(int i=1;i<=9;i++){
            check(i,n,k,v);
        }
        return v;
    }
};