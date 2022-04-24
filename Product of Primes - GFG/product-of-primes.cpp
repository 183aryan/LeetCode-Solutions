// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const long long mod = 1e9+7;
    bool is_prime(long long n){
            if(n == 1 || n == 0) return false;
            if(n == 2 || n == 3) return true;
            if(n%2 == 0) return false;
            for(long i = 3;i*i<=n;i++){
                if(n%i == 0) return false;
            }
            return true;
    }
    long long primeProduct(long long L, long long R){
        // code here
        long long prod = 1;
        for(long i=L;i<=R;i++){
            if(is_prime(i)){
                prod *= i;
                prod %= mod;
            }
        }
        return prod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends