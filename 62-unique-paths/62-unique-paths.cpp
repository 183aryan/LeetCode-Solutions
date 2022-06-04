class Solution {
public:
    int uniquePaths(int m, int n) {
        long long int N = m + n -2;
        long long int r = m - 1;
        long long int res = 1;
        
        for(int i=1;i<=r;i++){
            res = res*(N-r+i)/i;
        }
        return res;
    }
};