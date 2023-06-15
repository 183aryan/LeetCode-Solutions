class FindSumPairs {
public:
    vector<int> v1, v2;
    unordered_map<int, int> um;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto it:nums2) um[it]++;
        v1 = nums1;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        um[v2[index]]--;
        v2[index] += val;
        um[v2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto it:v1){
            if(um.count(tot - it)){
                cnt += um[tot-it];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */