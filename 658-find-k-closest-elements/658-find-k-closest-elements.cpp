class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push({abs(arr[i]-x),i});
        }
        
        for(int i=k;i<arr.size();i++){
            int diff = abs(arr[i]-x);
            if(pq.top().first > diff){
                pq.pop();
                pq.push({abs(arr[i]-x),i});
            }
        }
        while(pq.empty() == false){
            v.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};