class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        sort(begin(salary), end(salary));
        
        for(int i=1;i<size(salary)-1;i++) sum += salary[i];
        
        return (sum/(size(salary)-2));
    }
};