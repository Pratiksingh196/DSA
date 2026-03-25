class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> sumrow(m,0);
        vector<long long> sumcol(n,0);
        long long totalsum = 0;

        for(int i = 0 ; i< m ; i++){
            for(int j=0; j<n;j++){
                  totalsum+=grid[i][j];
                  sumrow[i] += grid[i][j];
                  sumcol[j] += grid[i][j];
            }
        }
        if(totalsum%2!=0) return false;

        long long upper = 0;

        for(int i = 0 ; i <sumrow.size() ; i++){
            upper += sumrow[i];
            long long lower = totalsum - upper;
            if(lower==upper){
                return true;
            }
        }

         upper = 0;
         for(int i = 0 ; i <sumcol.size() ; i++){
            upper += sumcol[i];
            long long lower = totalsum - upper;
            if(lower==upper){
                return true;
            }
        }

        return false;
    }
};