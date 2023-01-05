//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        set<string> s;
        
        for(auto it:words) s.insert(it);
        
        string ans;
        sort(words.begin(), words.end());
        
        for(int i=0;i<words.size();i++){
            bool flag = true;
            string s1;
            for(int j=0;j<words[i].size();j++){
                s1 += words[i][j];
                if(s.find(s1) == s.end()){
                    flag = false;
                    break;
                }
            }
            if(flag and ans.size() < s1.size()){
                ans = s1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends