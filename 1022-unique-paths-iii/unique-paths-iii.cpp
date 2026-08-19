class Solution {
public:
    vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};

    int dfs(vector<vector<int>>& grid, int i, int j, int remaining) {
        
        // Out of bounds
        if(i < 0 || j < 0 || 
           i >= grid.size() || j >= grid[0].size())
            return 0;

        // Obstacle or already visited
        if(grid[i][j] == -1 || grid[i][j] == 3)
            return 0;

        // Reached ending cell
        if(grid[i][j] == 2) {
            return remaining == 1;
        }

        // Mark current cell visited
        int temp = grid[i][j];
        grid[i][j] = 3;

        int ans = 0;

        for(auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            ans += dfs(grid, ni, nj, remaining - 1);
        }

        // Backtrack
        grid[i][j] = temp;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int si = 0, sj = 0;
        int total = 0;

        // Count all cells that must be visited
        // and find starting position
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] != -1)
                    total++;

                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }

        return dfs(grid, si, sj, total);
    }
};