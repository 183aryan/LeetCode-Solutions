class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            vector<int> v;
            int n = nums.size();
            // pre computation....
            
            // declared left and right array for storing left and right product respectively.
            int left[n], right[n];
            int prodL = 1, prodR = 1;

            // storing left product in left array.
            left[0] = 1;
            for (int i = 1; i < n; i++)
            {
                prodL = prodL *nums[i - 1];
                left[i] = prodL;
            }

            // storing right product in right array.
            right[n - 1] = 1;
            for (int i = n - 2; i >= 0; i--)
            {
                prodR = prodR *nums[i + 1];
                right[i] = prodR;
            }

            // main computation for the result.....
            for (int i = 0; i < n; i++)
            {
                v.push_back(left[i] *right[i]);
            }

            return v;
        }
};