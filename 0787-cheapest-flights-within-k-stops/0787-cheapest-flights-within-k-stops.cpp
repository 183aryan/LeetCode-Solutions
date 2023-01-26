class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {
            unordered_map<int,vector<pair<int, int>>> ump;
            
            for( auto x : flights )
            ump[x[0]].push_back( { x[1], x[2] } );
            
            priority_queue<vector < int>, vector< vector< int >>, greater<vector< int>>> pq;
            pq.push({ 0,src,0 });
            vector<int> dist(n+1,INT_MAX);
            while (!pq.empty())
            {
                auto x = pq.top();
                pq.pop();
        
                int cost = x[0];
                int curr = x[1];
                int stops = x[2];
                
                
                if(dist[curr] < stops) continue;
                dist[curr] = stops;
                if (curr == dst) return cost;
                if (stops > k) continue;
                
                for(auto it:ump[curr]){
                    pq.push({cost+it.second, it.first, stops+1});
                }
                
            }
            return -1;
        }
};