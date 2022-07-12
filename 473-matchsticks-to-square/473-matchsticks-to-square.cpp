class Solution {
public:
    bool traverse(vector<int>& matchsticks,int tar, vector<int>& sides,int ind){
        if(ind == matchsticks.size()){
            if(sides[0] == sides[1] and sides[1] == sides[2] and sides[2] == sides[3]) return true;
            return false;
        }
        
        for(int i=0;i<4;i++){
            if(sides[i] + matchsticks[ind] > tar) continue;
            
            int j = i-1;
            while(j >= 0){
                if(sides[i] == sides[j]) break;
                j -= 1;
            }
            if(j != -1) continue;
            
            sides[i] += matchsticks[ind];
            if(traverse(matchsticks,tar,sides,ind+1)) return true;
            sides[i] -= matchsticks[ind];
            
        }
        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() == 0) return false;
        
        int sum = 0;
        for(int m:matchsticks) sum += m;
        
        
        int tar = sum / 4;
        vector<int> sides(4,0);
        
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        return traverse(matchsticks,tar,sides,0);
    }
};