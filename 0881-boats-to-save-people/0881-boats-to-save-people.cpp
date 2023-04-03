class Solution
{
    public:
        int numRescueBoats(vector<int> &people, int limit)
        {
            sort(people.begin(), people.end());
            
            int lo = 0, hi = people.size()-1;
            int cntb=0;
            
            while(hi >= lo){
                if(people[lo] + people[hi] <= limit){
                    hi--;
                    lo++;
                }
                else hi--;
                
                cntb++;
            }
            return cntb;
        }
};