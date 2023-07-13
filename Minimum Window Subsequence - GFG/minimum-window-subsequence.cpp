//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string S, string T) {
        // string s = "";
        // int j = 0;
        // int mini = str1.size() + 1;
        
        // for(int i=0;i<str1.size();i++){
        //     if(str1[i] == str2[j]){
        //         j++;
        //         if(j == str2.size()){
        //             int end = i+1;
        //             j--;
        //             while(j >= 0){
        //                 if(str1[i] == str2[j]) j--;
        //                 i--;
        //             }
        //             j++;
        //             i++;
        //             if(end - i < mini){
        //                 mini = end - i;
        //                 s = str1.substr(i, end);
        //             }
        //         }
        //     }
        // }
        // return s;
        string window = "";
    int j = 0, min = S.length() + 1;
    
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == T[j]) {
            j++;
            
            if (j == T.length()) {
                int end = i + 1;
                j--;
                
                while (j >= 0) {
                    if (S[i] == T[j])
                        j--;
                    i--;
                }
                
                j++;
                i++;
                
                if (end - i < min) {
                    min = end - i;
                    window = S.substr(i, end - i);
                }
            }
        }
    }
    
    return window;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends