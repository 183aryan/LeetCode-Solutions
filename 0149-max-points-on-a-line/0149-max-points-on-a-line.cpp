class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 1;
        int total_points =0;
        for(int i=0 ;i<n ;i++)
        {
            map<double,int>mp;
            for(int j=i+1;j<n;j++)
            {
                double x  = (double)(points[j][1]-points[i][1]);
                double y  = (double)(points[j][0]-points[i][0]);
                double z  = (double)(x/y);
                if(x<0 && y==0) mp[abs(z)]++;
                else mp[z]++;
            }
            int temp = 0;
            for(auto it:mp)
               temp = max(temp, it.second+1);    
            total_points = max(temp, total_points);
        }
        return total_points;
    }
};