bool isSafe(vector<vector<char>>& grid,int row,int col,bool** visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        return((row>=0 && row<m) && (col>=0 && col<n) &&(grid[row][col]=='1' && !visited[row][col]));
    }
    void dfs(vector<vector<char>>& grid,int row,int col,bool** visited)
    {
        static int rowNbr[]={-1,-1,-1,0,0,1,1,1};
        static int colNbr[]={-1,0,1,-1,1,-1,0,1};
        visited[row][col]=true;
        for(int k=0;k<8;k++)
        {
            if(isSafe(grid,row+rowNbr[k],col+colNbr[k],visited))
            {
                dfs(grid,row+rowNbr[k],col+colNbr[k],visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int count = 0;//count of the islands present inthe graph
       bool** visited = new bool*[m];
        for(int i=0;i<m;i++)
        {
            visited[i]=new bool[n];
            for(int j=0;j<n;j++)
            {
                visited[i][j]=false;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    dfs(grid,i,j,visited);
                    ++count;
                }
            }
        }
        return count;
        
    }
};
