class Solution {
public:
    vector<vector<int>> ans;
    void check(vector<int>& temp,int k,int n,int start){
        if(k == temp.size()){
            if(n==0) ans.push_back(temp);
            return;
        }
        for(int i=start;i<=9;i++){
            temp.push_back(i);
            check(temp,k,n-i,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {  
        vector<int> temp;
        check(temp,k,n,1);
        return ans;
    }
};