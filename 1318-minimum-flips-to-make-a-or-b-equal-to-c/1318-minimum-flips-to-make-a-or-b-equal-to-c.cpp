class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a || b || c){
            int x = a&1;
            int y = b&1;
            int z = c&1;
            
            if((x | y) != z){
                if(z == 1) cnt++;
                else cnt += (x + y);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};