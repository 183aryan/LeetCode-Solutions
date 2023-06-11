class SnapshotArray {
public:
    vector<map<int,int>> arr;
    int s_id;
    SnapshotArray(int length) {
        arr.resize(length);
        s_id=0;
        for(int i = 0; i < length; i++) arr[i][0] = 0;
    }
    
    void set(int index, int val) {
        arr[index][s_id] = val;
    }
    
    int snap() {
        return s_id++;
    }
    
    int get(int index, int snap_id) {
        if(arr[index].find(snap_id) == arr[index].end()){
            return prev(arr[index].lower_bound(snap_id))->second;
        }
        return arr[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */