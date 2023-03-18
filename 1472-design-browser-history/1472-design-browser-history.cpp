class BrowserHistory {
public:
    vector<string> vs;
    int index;
    BrowserHistory(string homepage) {
        vs.push_back(homepage);
        index=0;
    }
    
    void visit(string url) {
        vs.resize(index+1);
        vs.push_back(url);
        index++;
    }
    
    string back(int steps) {
        int idx = max(0, index - steps);
        index = idx;
        return vs[index];
    }
    
    string forward(int steps) {
        int idx = min((int)vs.size() - 1, index + steps);
        index = idx;
        return vs[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */