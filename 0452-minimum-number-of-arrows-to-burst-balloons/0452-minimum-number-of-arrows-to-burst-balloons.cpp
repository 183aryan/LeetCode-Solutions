class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt=1;
        sort(points.begin(), points.end());
        
        int last = points[0][1];
        
        for(int i=1;i<points.size();i++){
            if(points[i][0] > last)
            {
                cnt++;
                last = points[i][1];
            }
            else last = min(last, points[i][1]);
        }
        return cnt;
    }
};