//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        map<int,vector<int>> mp;
        
        
        for(int i=0;i<n;i++)
        {  
            mp[arr[i].dead].push_back(arr[i].profit);
        }
        
        priority_queue<int> pq;
        
        auto cur=--mp.end();
        
        int mxdeadline=cur->first;
        
        int ans1=0,ans2=0;
        
        
        while(mxdeadline)
        {  
            for(auto x:mp[mxdeadline])
            {  
                pq.push(x);
            }
            
            if(!pq.empty())
            { 
                ans1+=pq.top();pq.pop();
                ans2++;
            }
            mxdeadline--;
        }
        
        
        return {ans2,ans1};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends