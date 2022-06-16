// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        unordered_set<char> s;
        for(int i=0;i<str.size();i++) s.insert(str[i]);
        int ans = INT_MAX;
        unordered_map<char,int> m;
        int j=0;
        for(int i=0;i<str.size();i++){
            m[str[i]]++;
            if(s.size() == m.size()){
                while(m[str[j]] > 1){
                    m[str[j]]--;
                    j++;
                }
                ans = min(ans,i-j+1);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends