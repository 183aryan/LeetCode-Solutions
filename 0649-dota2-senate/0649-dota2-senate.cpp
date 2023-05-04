class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        
        for(int i=0;i<senate.size();i++){
            if(senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        
        while(!radiant.empty() and !dire.empty()){
            int x = radiant.front();
            int y = dire.front();
            
            radiant.pop();
            dire.pop();
            
            (x < y)?radiant.push(x + senate.size()):dire.push(y + senate.size());
        }
        
        return (radiant.size() > dire.size()) ? "Radiant" : "Dire";
    }
};