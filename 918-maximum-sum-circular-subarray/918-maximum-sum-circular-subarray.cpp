class Solution
{
    public:
    // using Kadane's algorithm
        int maxNormalSum(vector<int> &nums)
        {
            int res = nums[0];
            int maxEnding = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                maxEnding = max(maxEnding + nums[i], nums[i]);
                res = max(res, maxEnding);
            }
            return res;
        }
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int normal = maxNormalSum(nums);
        if (normal < 0) return normal;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = -nums[i];
        }
        int circular = sum + maxNormalSum(nums);

        return max(normal, circular);
    }
};