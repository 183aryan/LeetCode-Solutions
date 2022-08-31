class Solution {
public:
    void fnc(vector<vector<int>>& heights,int i, int j,int prev,vector<vector<int>>& ocean)
    {
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size())
            return;
        if(ocean[i][j]==1)
            return;
        if(heights[i][j]<prev)
            return;
        
        ocean[i][j]=1;
        
        fnc(heights,i+1,j,heights[i][j],ocean); 
        fnc(heights,i,j+1,heights[i][j],ocean);
        fnc(heights,i-1,j,heights[i][j],ocean);
        fnc(heights,i,j-1,heights[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        
        if(heights.size()<1)return ans;
        
        vector<vector<int>>pacific(heights.size(),vector<int>(heights[0].size(),0));
        
        vector<vector<int>>atlantic(heights.size(),vector<int>(heights[0].size(),0));
        
        for(int col=0;col<heights[0].size();col++)
        {
            fnc(heights,0,col,INT_MIN,pacific);
            fnc(heights,heights.size()-1,col,INT_MIN,atlantic);    
        }
        
        for(int row = 0;row<heights.size();row++)
        {
            fnc(heights,row,0,INT_MIN,pacific);
            fnc(heights,row,heights[0].size()-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                    vector<int>v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }
        
        
        
        return ans;
    }
};