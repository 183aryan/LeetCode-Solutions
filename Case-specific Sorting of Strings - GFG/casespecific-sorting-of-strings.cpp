//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        string cap_s = "";
        string sml_s = "";
        
        for(int i=0;i<n;i++){
            if(s[i] >= 'A' and s[i] <= 'Z') cap_s += s[i];
            if(s[i] >= 'a' and s[i] <= 'z') sml_s += s[i];
        }
        
        sort(cap_s.begin(), cap_s.end());
        sort(sml_s.begin(), sml_s.end());
        
        string ans = "";
        
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                ans += cap_s[j];
                j++;
            }
            else{
                ans += sml_s[k];
                k++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends