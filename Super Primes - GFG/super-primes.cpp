// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    vector<int> checkPrime(n+1,1);
	    checkPrime[0] = checkPrime[1] = 0;
	    
	    for(int i=2;i*i<=n;i++){
	        if(checkPrime[i]){
	            for(int j=i*i;j<=n;j+=i){
	                checkPrime[j] = 0;
	            }
	        }
	    }
	    int res = 0;
	    for(int i=2;i<=n;i++){
	        if(checkPrime[i] and checkPrime[i-2]) res++;
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends