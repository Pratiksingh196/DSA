class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;

        for(int i = 0 ; i <n ; i++){
            for(int j = 0 ; j < m ; j++){
                arr.push_back(grid[i][j]);
            }
        }

        int nk = k % (n*m);

        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + nk);
        reverse(arr.begin() + nk, arr.end());

        for(int i = 0 ; i< n ; i ++){
            for(int j = 0 ; j < m ; j++){
                grid[i][j] = arr[i*m+j];
            }
        }

        return grid;
    }
};