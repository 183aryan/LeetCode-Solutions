//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	   // int i=0, j=n-1;
	   // while(i < j){
	   //     while(arr[i]%2 == 0 and i < j) i++;
	   //     while(arr[j]%2 == 1 and i < j) j--;
	        
	   //     if(i < j){
	   //         swap(&arr[i], &arr[j]);
	   //         i++;
	   //         j--;
	   //     }
	   // }
	   // sort(arr, arr+i);
	   // sort(arr+j+1, arr+n);
	   int i=0,j=n-1;
        while(true){
           do{i++;}while(!(arr[i]%2));
           do{j--;}while(arr[j]%2);
           if(j<=i)
           break;
           swap(arr[i],arr[j]);
        }
        j++;
        sort(arr,arr+j);
        sort(arr+j,arr+n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends