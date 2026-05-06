class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++){
            int p = 0;
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]=='.'){
                    swap(grid[i][j],grid[i][p]);
                    p++;
                }else if(grid[i][j]=='*'){
                    p =j+1;
                }
                
            }
        }
        vector<vector<char>> res(n,vector<char>(m));

        for(int i = 0 ; i< m ; i++){
            for(int j=0 ; j <n ; j++){
                res[j][m-1-i]= grid[i][j];
            }
        }
        return res;

    }
};