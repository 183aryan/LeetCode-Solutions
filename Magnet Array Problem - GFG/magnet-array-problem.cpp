// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        double binary_search(double lo,double hi,double magnets[],int n){
            while(hi > lo){
                double mid = lo + (hi-lo)/2;
                double netForce = 0.0,minForce = 1e-9;
                
                for(int i=0;i<n;i++){
                    netForce += 1/(mid-magnets[i]);
                }
                if((netForce) > minForce) lo = mid;
                else if((netForce) <- minForce) hi = mid;
                else return mid;
            }
        }
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here   
        for(int i=0;i<n-1;i++){
            getAnswer[i] = binary_search(magnets[i],magnets[i+1],magnets,n);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends