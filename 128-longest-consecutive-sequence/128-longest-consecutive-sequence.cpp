class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if(nums.size() == 0) return 0;
            unordered_set<int> s;	// O(1)
            for (int i = 0; i < nums.size(); i++)
            {
                s.insert(nums[i]);
            }
            int ans = 0;
            for (auto &x: s)
            {
                int cnt = 1;
                for (int j = 1; s.count(x - j); j++)
                {
                	// works in O(1)
                    s.erase(x - j);
                    cnt++;
                }
                for (int j = 1; s.count(x + j); j++)
                {
                	// works in O(1)
                    s.erase(x + j);
                    cnt++;
                }
                ans = max(ans, cnt);
            }
            return ans;
        }
};