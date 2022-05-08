/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> v;
    int i=0;
    int res;
    NestedIterator(vector<NestedInteger> &nestedList) {
        pushElements(nestedList,v);
    }
    void pushElements(vector<NestedInteger> &nestedList, vector<int> &v){
        for(auto x:nestedList){
            if(x.isInteger()) v.push_back(x.getInteger());
            else{
                pushElements(x.getList(),v);
            }
        }
    }
    int next() {
        if(i < v.size())
        res = v[i];
        i++;
        return res;
    }
    
    bool hasNext() {
        if(i < v.size()) return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */