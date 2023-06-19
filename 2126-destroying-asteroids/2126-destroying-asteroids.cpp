class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long int m = mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i] <= m) m += asteroids[i];
            else return false;
        }
        return true;
    }
};