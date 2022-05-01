class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {
            stack<char> s1, s2;
            for(int i=0;i<s.size();i++)
            {
                if (s[i] == '#'
                    and!s1.empty())
                {
                    s1.pop();
                }
                else if (s[i] != '#') s1.push(s[i]);
            }
            for(int j=0;j<t.size();j++)
            {
                if (t[j] == '#'
                    and!s2.empty()) s2.pop();
                else if (t[j] != '#') s2.push(t[j]);
            }
            return s1 == s2;
        }
};