class Solution
{
    public:
        int pivotIndex(vector<int> &nums)
        {
            int sum = 0;
            int curr_sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
            }
            for (int i = 0; i < nums.size(); i++)
            {
                sum -= nums[i];
                if (curr_sum == sum) return i;
                curr_sum += nums[i];
            }
            return -1;
        }
};