//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void f(int index, string& str, string& s, set<string>& vs){
	        if(index == s.size()){
	            vs.insert(s);
	            return;
	        }
	        for(int i=index;i<s.size();i++){
	            swap(s[i], s[index]);
	            f(index+1, str, s, vs);
	            swap(s[i], s[index]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		  //  sort(S.begin(), S.end());
		    set<string> vs;
		    string str = "";
		    f(0, str, S, vs);
		    vector<string> ans(vs.begin(), vs.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends