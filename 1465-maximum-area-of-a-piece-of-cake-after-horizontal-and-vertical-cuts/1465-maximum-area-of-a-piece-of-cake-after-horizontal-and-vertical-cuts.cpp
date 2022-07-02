class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        
        int one = hor[0],two = ver[0];
        for(int i=1;i<hor.size();i++){
            one = max(one,abs(hor[i] - hor[i-1]));
        }
        one = max(one,h-hor[hor.size()-1]);
        
        for(int i=1;i<ver.size();i++){
            two = max(two,abs(ver[i] - ver[i-1]));
        }
        two = max(two,w-ver[ver.size()-1]);
        
        return (long)one*two % 1000000007;
    }
};