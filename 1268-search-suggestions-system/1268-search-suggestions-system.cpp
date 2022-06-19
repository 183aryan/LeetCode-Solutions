class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> v;
        sort(products.begin(),products.end());
        
        for(int i=0;i<searchWord.size();i++){
            string s = searchWord.substr(0,i+1);
            int cnt = 0;
            vector<string> temp;
            for(int j=0;j<products.size() and cnt < 3;j++){
                if(products[j].find(s) == 0){
                    temp.push_back(products[j]);
                    cnt++;
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};