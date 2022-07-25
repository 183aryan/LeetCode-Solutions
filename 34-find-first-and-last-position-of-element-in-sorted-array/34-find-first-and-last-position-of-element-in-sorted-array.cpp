class Solution
{
    public:
        int first(int s, int e, vector<int> &nums, int target,int ans)
        {
            if (s > e) return ans;
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                return first(s, mid - 1, nums, target,ans);
            }
            else if (nums[mid] > target)
            {
                return first(s, mid - 1, nums, target,ans);
            }
            else
            {
                return first(mid + 1, e, nums, target,ans);
            }
            return ans;
        }

    int last(int s, int e, vector<int> &nums, int target, int ans)
    {
        if (s > e) return ans;
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            return last(mid + 1, e, nums, target, ans);
        }
        else if (nums[mid] > target)
        {
            return last(s, mid - 1, nums, target, ans);
        }
        else
        {
            return last(mid + 1, e, nums, target, ans);
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int f, l;
        f = first(start, end, nums, target, -1);
        l = last(start, end, nums, target, -1);
        return {
            f,
            l
        };
    }
};