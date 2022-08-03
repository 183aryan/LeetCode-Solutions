class MyCalendar {
public:
    unordered_map<int,int> um;
    MyCalendar() {
        // Mycalender myCalender = new MyCalender();
        // map<int,int> m;
    }
    
    bool book(int start, int end) {
        for(auto [s,e]:um){
            if(!(start >= e || s >= end)) return false;
        }
        um[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */