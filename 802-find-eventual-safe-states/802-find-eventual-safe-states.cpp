class Solution
{
    public:
        bool DFS(int s, vector<vector < int>> &graph, vector< bool > &visited, vector< bool > &recSt, vector< bool > &cycle)
        {
            visited[s] = true;
            recSt[s] = true;
            for (auto x: graph[s])
            {
                if (!visited[x])
                {
                    if (DFS(x, graph, visited, recSt, cycle) == true)
                    {
                        cycle[s] = true;   // source s is present in any cycle
                        return true;
                    }
                }
                else if (recSt[x] == true)
                {
                    cycle[s] = true;    // source s is present in any cycle
                    return true;
                }
            }
            recSt[s] = false;
            return false;
        }
    vector<int> eventualSafeNodes(vector<vector < int>> &graph)
    {
        vector<int> v;
        vector<bool> visited(graph.size(), false), recSt(graph.size(), false), cycle(graph.size(), false);

        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {
                DFS(i, graph, visited, recSt, cycle);
            }
        }

        for (int i=0;i<graph.size();i++)
        {
            if (!cycle[i]) v.push_back(i);
        }

        return v;
    }
};