class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
        int total = 0;
        for(auto x:boxTypes){
            int no = x[0];
            int units = x[1];
            if(truckSize > 0){
                total += min(truckSize,no)*units;
                truckSize -= no;
            }
        }
        return total;
    }
};