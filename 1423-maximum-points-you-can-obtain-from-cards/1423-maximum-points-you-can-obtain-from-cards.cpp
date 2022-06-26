class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0,sum = 0,res = 0, n = cardPoints.size();
        for(int i=0;i<n;i++) sum += cardPoints[i];
        
        if(n == k) return sum;
        
        for(int i=0;i<n-k-1;i++){
            res += cardPoints[i];
        }
        
        for(int i=n-k-1;i<n;i++){
            res += cardPoints[i];
            total = max(total,sum-res);
            res -= cardPoints[i-(n-k-1)];
        }
        
        return total;
    }
};