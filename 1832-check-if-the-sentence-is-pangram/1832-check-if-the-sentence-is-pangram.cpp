class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>st;
    for(auto e:sentence)
        st.insert(e);
    return st.size()==26;
    }
};