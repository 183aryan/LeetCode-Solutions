class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int cnt1 = 0, cnt2 = 0, a=-1, b=-1;
    
    for(int i=0;i<nums.size();i++){
        if (a==nums[i]){
            cnt1++;
        }
        else if (b==nums[i]){
            cnt2++;
        }
        else if (cnt1==0){
            a = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0){
            b = nums[i];
            cnt2 = 1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1 = cnt2 = 0;
    for(int i=0;i<nums.size();i++){
        if (nums[i]==a)   cnt1++;
        else if (nums[i]==b)  cnt2++;
    }
    
    vector<int> v;
    if (cnt1 > nums.size()/3)   v.push_back(a);
    if (cnt2 > nums.size()/3)   v.push_back(b);
    return v;
  }
};