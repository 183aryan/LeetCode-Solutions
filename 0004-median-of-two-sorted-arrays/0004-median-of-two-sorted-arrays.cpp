class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int lo = 0, hi = n1;
            if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

            while (lo <= hi)
            {
                int i1 = (hi + lo) / 2;
                int i2 = (n2 + n1 + 1) / 2 - i1;

                double min1 = (i1 == n1) ? INT_MAX : nums1[i1];
                double max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
                double min2 = (i2 == n2) ? INT_MAX : nums2[i2];
                double max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];

                if (max1 <= min2 and max2 <= min1)
                {
                    if ((n1 + n2) % 2 == 0) return (max(max1, max2) + min(min1, min2)) / 2;
                    else return max(max1,max2);
                }
                else if (max1 > min2) hi = i1 - 1;
                else lo = i1 + 1;
            }
         return 0.0;
    }
};