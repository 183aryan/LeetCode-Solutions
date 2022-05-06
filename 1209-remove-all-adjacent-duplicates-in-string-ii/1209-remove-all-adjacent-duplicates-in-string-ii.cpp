class Solution
{
    public:
        string removeDuplicates(string s, int k)
        {
            vector<pair<char, short>> st;
            string ans;
            for (auto c: s)
            {
                if (st.empty() || st.back().first != c) st.push_back({ c,
                    0 });
                if (++st.back().second == k) st.pop_back();
            }
            for (auto &p: st) ans += string(p.second, p.first);
            return ans;
        }
};