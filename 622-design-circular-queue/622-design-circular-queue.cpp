class MyCircularQueue {
public:
    vector<int> v;
    int maxsize, head=0,tail=-1;
    MyCircularQueue(int k) {
        v.resize(k);
        maxsize=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        tail = (tail+1)%maxsize;
        v[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(head == tail){
            head=0;
            tail=-1;
        }
        else{
            head = (head+1)%maxsize;
        }
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1:v[head];
    }
    
    int Rear() {
        return isEmpty() ? -1:v[tail];
    }
    
    bool isEmpty() {
        if(tail == -1) return true;
        return false;
    }
    
    bool isFull() {
        if(isEmpty() == false and head == (tail+1)%maxsize) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */