class MyCalendarThree {
public:
    int maxCnt = 0;
    map<int, int> m;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); it++) 
        {
            // cout << it->first << " " << it->second << endl;
            cnt += it->second;
            // cout << cnt << endl;
            maxCnt = max(cnt, maxCnt);
            // cout << maxCnt << endl;
        }
        return maxCnt;   
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */