class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        
        for(auto it:pushed){
            pushed[i] = it;
            i++; // so thaat if top does not matches then it should not modify any other value...
            while(i > 0 and pushed[i-1] == popped[j]){
                i--;
                j++;
            }
        }
        
        return i == 0;
    }
};