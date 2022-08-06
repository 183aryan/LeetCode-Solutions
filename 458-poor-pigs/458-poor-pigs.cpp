class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest/minutesToDie;
        
        int states = rounds + 1;
        
        int pigs = 0;
        
        while(pow(states,pigs) < buckets) pigs++;
        
        return pigs;
    }
};