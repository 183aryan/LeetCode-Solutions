class Solution {
public:
    vector<int> f(int n){
        vector<int> arr(10);
        while(n>0){
            arr[n%10]++;
            n /= 10;
        }
        return arr;
    }
    bool reorderedPowerOf2(int n) {        
        vector<int> v = f(n);
        
        int x = 1;
        
        for(int i=0;i<=30;i++){
            if(v == f(x)) return true;
            
            x = x<<1;
        }
        return false;
    }
};