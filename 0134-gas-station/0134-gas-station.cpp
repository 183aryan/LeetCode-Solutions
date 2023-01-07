class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int cnt=0;
        int n=gas.size();
//         for(int i=0;i<n;i++){
//             int to_stop=0;
//             int j=i;
//             int fuel = 0;
//             while(to_stop < n){
//                 fuel += (gas[j%n] - cost[j%n]);
                
//                 if(fuel < 0) break;
                
//                 to_stop++;
//                 j++;
//             }
//             if(to_stop == n){
//                 return i;
//             }
//         }
//         return -1;
        int tot_gas=0;
        int tot_cost=0;
        
        for(int i=0;i<n;i++){
            tot_gas += gas[i];
            tot_cost += cost[i];
        }
        
        if(tot_cost > tot_gas) return -1;
        int index=0;
        int fuel=0;
        for(int i=0;i<n;i++){
            fuel += (gas[i] - cost[i]);
            if(fuel < 0){
                fuel = 0;
                index = i+1;
            }
        }
        return index;
    }
};