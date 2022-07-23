class Solution {
public:
    void merge(vector<int>& cnt, vector<pair<int,int>>& vp, int left,int mid,int right){
        vector<pair<int,int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid and j <= right){
            if(vp[i].first <= vp[j].first){
                temp[k] = vp[j];
                k++;
                j++;
            }
            else{
                cnt[vp[i].second] += right-j+1;
                temp[k] = vp[i];
                k++;
                i++;
            }
        }
        while(i <= mid){
            temp[k++] = vp[i++];
        }
        while(j <= right){
            temp[k++] = vp[j++];
        }
        
        for(int i=left;i<=right;i++) vp[i] = temp[i-left];
    }
    void mergeSort(vector<int>& cnt, vector<pair<int,int>>& vp,int left,int right){
        if(left < right){
            int mid = left + (right - left)/2;
            mergeSort(cnt,vp,left,mid);
            mergeSort(cnt,vp,mid+1,right);
            merge(cnt,vp,left,mid,right);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> vp(n);
        
        for(int i=0;i<n;i++){
            // vp.push_back({nums[i],i});
            pair<int,int> x;
            x.first = nums[i];
            x.second = i;
            vp[i] = x;
        }
        
        vector<int> cnt(n,0);
        mergeSort(cnt,vp,0,n-1);
        
        return cnt;
    }
};