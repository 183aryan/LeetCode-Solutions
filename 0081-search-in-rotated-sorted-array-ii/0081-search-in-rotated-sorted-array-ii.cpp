class Solution {
public:
    bool search(vector<int>& A, int k) {
        int n = A.size();
        int lo = 0, hi = n - 1;
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            
            if(A[mid] == k) return true;
            if(A[lo] == A[mid] and A[mid] == A[hi]){
                lo = lo + 1;
                hi = hi - 1;
                continue;
            }
            if(A[lo] <= A[mid]){
                if(A[lo] <= k and k <= A[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else{
                if(k >= A[mid] and k <= A[hi]){
                    lo = mid + 1;
                }
                else hi = mid-1;
            }
        }
        return false;
    }
};