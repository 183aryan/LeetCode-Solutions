class Solution
{
    public:
        void shift(vector<vector < int>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            int x = grid[m-1][n-1];

            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if(i == 0) grid[i][j] = grid[i][n-1];
                    if (j == 0 and i > 0) 
                    {
                        grid[i][j] = grid[i - 1][n - 1];
                    }
                    if (j > 0) grid[i][j] = grid[i][j - 1];
                }
            }
            grid[0][0] = x;
        }
    vector<vector < int>> shiftGrid(vector<vector < int>> &grid, int k)
    {

        while (k--)
        {
            shift(grid);
        }
        return grid;
    }
};