class FrontMiddleBackQueue {
    deque<int> q;
public:
    FrontMiddleBackQueue() {
        deque<int> q;
    }
    
    void pushFront(int val) {
        q.push_front(val);
    }
    
    void pushMiddle(int val) {
        int len = q.size();
        deque<int>::iterator it = q.begin();
        len = len/2;
        q.insert(it+len,val);
    }
    
    void pushBack(int val) {
        q.push_back(val);
    }
    
    int popFront() {
        if(q.size() == 0) return -1;
        int val = q.front();
        q.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(q.size() == 0) return -1;
        int len = q.size();
        if(len%2) len = len/2;
        else{ len = len/2; len--;}
        
        stack<int> s;
        for(int i=0;i<=len;i++){
            s.push(q.front());q.pop_front();
        }
        int val = s.top();
        s.pop();
        while(!s.empty()){
            q.push_front(s.top());
            s.pop();
        }
        return val;
    }
    
    int popBack() {
        if(q.size() == 0) return -1;
        int val = q.back();
        q.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */