//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // for(int i=0;i<m;i++){
        //     if(seats[i] == 0){
        //         if(i-1>=0 and seats[i-1]==1) continue;
        //         if(i+1<m and seats[i+1]==1) continue;
        //         n--;
        //         seats[i] == 1;
        //     }
        // }
        // if(n <= 0) return true;
        // return false;
        for(int i = 0; i < m; i++) {

            // if seats is 0 then i will try to put 1, otherwise do nothing
            if(seats[i] == 0) {

                // prev is 1 then continue;
                if(i -1 >= 0 and seats[i-1] == 1) {
                    continue; 
                }
                

                // next is 1, then continue; 
                if(i + 1 < m and seats[i+1] == 1) {
                    continue; 
                }

 

               // othewise put 1, reduce n
                n--; 
                seats[i] = 1; 
            }
        }
        // cout << n << endl; 
        if(n <= 0) return true; 
        return false; 
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends