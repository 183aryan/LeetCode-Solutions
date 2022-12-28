class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> pq;
        
        for(auto it:piles) pq.push(it);
        
        while(k > 0){
            int x = pq.top();
            pq.pop();
            pq.push(x - floor(x/2));
            k--;
        }
        
        int sum=0;
        while(pq.size()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};