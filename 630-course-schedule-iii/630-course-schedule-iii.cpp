class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        
        int timeConsumed = 0;
        for(auto x:courses){
            timeConsumed += x[0];
            pq.push(x[0]);
            if(timeConsumed > x[1]){
                timeConsumed -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};