class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
            vector<int> v(nums.size());	// runtime error getting for not declaring the size of vector which is to be returned.
            int pos = 0, neg = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > 0)
                {
                    v[pos] = nums[i];
                    pos += 2;
                }
                else if (nums[i] < 0)
                {
                    v[neg] = nums[i];
                    neg += 2;
                }
            }
            return v;
        }
};