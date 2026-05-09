class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m/2,n/2);

        for(int i = 0 ; i < layers ; i++){
            vector<int> nums;
            int top = i;
            int bottom = m-i-1;
            int left = i;
            int right = n-i-1;

            for(int j = left ; j <=right; j ++){
                nums.push_back(grid[top][j]);
            }
            for(int j = top+1 ; j <=bottom-1; j ++){
                nums.push_back(grid[j][right]);
            }
            for(int j = right ; j >=left; j --){
                nums.push_back(grid[bottom][j]);
            }
            for(int j = bottom-1 ; j >=top+1; j --){
                nums.push_back(grid[j][left]);
            }
            int l = nums.size();
            int k2 = k % l ;

            rotate(begin(nums) , begin(nums)+k2 , end(nums));
            int idx = 0;

            for(int j = left ; j <=right; j ++){
               grid[top][j] = nums[idx];
               idx++;
            }
            for(int j = top+1 ; j <=bottom-1; j ++){
                grid[j][right] = nums[idx];
                idx++;
            }
            for(int j = right ; j >=left; j --){
                grid[bottom][j] = nums[idx];
                idx++;
            }
            for(int j = bottom-1 ; j >=top+1; j --){
                grid[j][left] = nums[idx];
                idx++;
            }

        }
        return grid;
    }
};