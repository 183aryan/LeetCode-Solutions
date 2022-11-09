class StockSpanner {
public:
    stack<pair<int,int>> sp;
    StockSpanner() {
        // stack<pair<int,int>> sp;
    }
    
    int next(int price) {
        int cnt = 1;
        while(!sp.empty() and sp.top().first <= price){
            cnt += sp.top().second;
            cout << cnt << " " << sp.top().second << endl;
            sp.pop();
        }
        sp.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */