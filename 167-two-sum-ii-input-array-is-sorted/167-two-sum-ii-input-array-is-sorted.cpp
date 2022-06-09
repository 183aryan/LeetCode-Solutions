class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0,hi = numbers.size()-1;
        while(hi > lo){
            if(numbers[lo]+numbers[hi] == target) return {lo+1,hi+1};
            else if(numbers[lo]+numbers[hi] > target) hi--;
            else lo++;
        }
        return {};
    }
};