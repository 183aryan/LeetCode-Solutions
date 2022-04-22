class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> v;
        int llv = 1;
        int val = 0;
        while(val<label){
            val += llv;
            llv *= 2;
        }
        llv /= 2;
        
        while(label != 1){
            v.push_back(label);
            int x = 3*llv - label - 1;      // finding complement...........
            int temp = x/2;
            label = temp;
            llv /= 2;
        }
        v.push_back(1);
        reverse(v.begin(),v.end());
        
        return v;
    }
};