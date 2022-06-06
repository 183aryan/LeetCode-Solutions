// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<long long,long long> um;
        long long cnt = 0;
        for(int i=0;i<n;i++){
            int r = A[i]%K; // checking for remainder whether divisble by k or not
            cnt += um[(K-r)%K]; // finding remainder's complement in the map
            um[r]++; // storing the remainder in the map
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends