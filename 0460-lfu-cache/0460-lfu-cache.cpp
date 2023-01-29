class Node{
    public:
        int key;
        int val;
        int frequency;
        Node* next;
        Node* prev;

        Node(int k, int v, int freq){
            key = k;
            val = v;
            frequency = freq;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList{
    public:
        Node* left;
        Node* right;
        int size;

        DoublyLinkedList(){
            left = new Node(-1, -1, 0);
            right = new Node(-1, -1, 0);
            left->next = right;
            right->prev = left;
            size = 0;
        }

        void insert(Node* node){
            Node* right_prev = right->prev;
            right_prev->next = node;

            node->prev = right_prev;            
            node->next = right;
            
            right->prev = node;

            size += 1;
        }

        void remove_lru(){
            Node* left_next = left->next;
            
            left->next =  left_next->next;
            left_next->next->prev = left;

            left_next->next = nullptr;
            left_next->prev = nullptr;

            size -= 1;
        }

        void remove(Node* node){
            Node* node_prev = node->prev;
            Node* node_next = node->next;

            node_prev->next = node_next;
            node_next->prev = node_prev;

            node->next = nullptr;
            node->prev = nullptr;

            size -= 1;
        }

        int getSize(){
            return size;
        }
};

class LFUCache {
public:
  int cap;
    int cur_min;
    // using for Node object of some key
    unordered_map<int, Node*> key_val_map;

    // using for preserving the order of elements (for some frequency) 
    // based on least recent use 
    unordered_map<int, DoublyLinkedList*> freq_map;
    LFUCache(int capacity) {
        cur_min = 1;
        cap = capacity;
    }
    
    int get(int key) {
        if (key_val_map.find(key) == key_val_map.end()){
            return -1;
        }

        int res = key_val_map[key]->val;

        freq_map[key_val_map[key]->frequency]->remove(key_val_map[key]);

        if (freq_map[key_val_map[key]->frequency]->getSize() == 0 && cur_min == key_val_map[key]->frequency){                
            cur_min = key_val_map[key]->frequency + 1;
            freq_map.erase(key_val_map[key]->frequency);
        }

        key_val_map[key]->frequency += 1;

        if (freq_map.find(key_val_map[key]->frequency) == freq_map.end()){
            DoublyLinkedList* dll = new DoublyLinkedList();
            freq_map[key_val_map[key]->frequency] = dll;
        }

        freq_map[key_val_map[key]->frequency]->insert(key_val_map[key]);

        return res;
    }
    
    void put(int key, int value) {
        if (key_val_map.find(key) == key_val_map.end()){
            Node* new_node = new Node(key, value, 1);
            key_val_map[key] = new_node;
            
            if (freq_map.find(1) == freq_map.end()){
                DoublyLinkedList* dll = new DoublyLinkedList();
                freq_map[1] = dll;
            }

            freq_map[1]->insert(new_node);

            if (key_val_map.size() > cap){
                key_val_map.erase(freq_map[cur_min]->left->next->key);
                freq_map[cur_min]->remove_lru();   

                if (freq_map[cur_min]->getSize() == 0){
                    freq_map.erase(cur_min);
                }
            }

            cur_min = 1;
        }
        else{
            freq_map[key_val_map[key]->frequency]->remove(key_val_map[key]);

            if (freq_map[key_val_map[key]->frequency]->getSize() == 0 && cur_min == key_val_map[key]->frequency){
                cur_min = key_val_map[key]->frequency + 1;
                freq_map.erase(key_val_map[key]->frequency);
            }

            key_val_map[key]->val = value;
            key_val_map[key]->frequency += 1;

            if (freq_map.find(key_val_map[key]->frequency) == freq_map.end()){
                DoublyLinkedList* dll = new DoublyLinkedList();
                freq_map[key_val_map[key]->frequency] = dll;
            }

            freq_map[key_val_map[key]->frequency]->insert(key_val_map[key]);
        }
    }
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */