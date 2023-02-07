class Solution {
public:
    int getMaxLen(vector<int>& arr) {
        int n=arr.size();
        int prod=1;
        int tLen=0;
        int ansLen=0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                tLen=0;
                prod=1;
                continue;
            }
            else if(arr[i] > 0){
                prod *= 1;
                tLen++;
            }
            else{
                prod *= -1;
                tLen++;
            }
            if(prod > 0) ansLen = max(ansLen, tLen);
        }
        prod = 1;
        tLen=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i] == 0){
                tLen=0;
                prod=1;
            }
            else if(arr[i] > 0){
                prod *= 1;
                tLen++;
            }
            else{
                prod *= -1;
                tLen++;
            }
            if(prod > 0) ansLen = max(ansLen, tLen);
        }
        return ansLen;
    }
};