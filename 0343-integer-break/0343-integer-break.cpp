class Solution {
public:
    int f(int n, int i){
        if(n == 0) return 1;
        if(n < 0 || i <= 0) return 0;
        
        int notTake = f(n, i-1);
        int take = i*f(n-i, i);
        
        return max(take, notTake);
    }
    int integerBreak(int n) {
        return f(n, n-1);
    }
};