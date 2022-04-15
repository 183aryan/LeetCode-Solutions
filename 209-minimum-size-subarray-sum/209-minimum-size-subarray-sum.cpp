class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
            int s = 0, e = 0, sum = 0;
            int window = INT_MAX;
            if (nums.size() < 2) return 0;
            for (e = 0; e < nums.size(); e++)
            {
                sum += nums[e];

                if (sum >= target)
                {
                    while (sum >= target)
                    {
                        sum -= nums[s];
                        s++;
                    }
                    window = min(window, e - s + 2);
                }
            }
            if (window == INT_MAX) return 0;
            else return window;
        }
};