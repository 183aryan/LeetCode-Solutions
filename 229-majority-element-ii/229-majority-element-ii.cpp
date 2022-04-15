class Solution
{
    public:

    vector<int> majorityElement(vector<int> &nums){

    unordered_map<int, int> m;
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (auto x: m)
    {
        if (x.second > nums.size() / 3)
        {
            v.push_back(x.first);
        }
    }
    return v;
}
};