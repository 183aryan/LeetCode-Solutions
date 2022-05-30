class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 1<<31 and divisor == -1) return INT_MAX;
        
        bool sign = true;
        if((dividend >= 0 and divisor >= 0) || (dividend < 0 and divisor < 0)) sign = true;
        else sign = false;
        
        long long int a = abs(dividend);
        long long int b = abs(divisor);
        
        long long int res = 0;
        while(a - b >= 0){
            long long int cnt=0;
            while(a - (b << 1 << cnt) >= 0) cnt++; 
            res += 1 << cnt;
            a -= b << cnt;
        }
        if(sign) return res;
        return -res;
        
    }
};