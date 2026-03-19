class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> SumX(m,vector<int>(n,0));
        vector<vector<int>> SumY(m,vector<int>(n,0));

        int count = 0;

        for(int i = 0; i<m ; i++){
            for(int j =0 ; j<n;j++){

                SumX[i][j] = (grid[i][j]=='X');
                SumY[i][j] = (grid[i][j]=='Y');

                if(i-1 >= 0) {
                    SumX[i][j] += SumX[i-1][j];
                    SumY[i][j] += SumY[i-1][j];
                    }

                if(j-1 >= 0) {
                    SumX[i][j] += SumX[i][j-1];
                    SumY[i][j] += SumY[i][j-1];
                    }

                if(i-1 >= 0 && j-1 >=0) {
                    SumX[i][j] -= SumX[i-1][j-1];
                    SumY[i][j] -= SumY[i-1][j-1];
                    }

                if(SumX[i][j]==SumY[i][j] && SumX[i][j]>0){
                    count++;
                }
            }
        }

        return count;
    }
};