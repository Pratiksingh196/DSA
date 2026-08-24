class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rows(n);
        vector<bool> cols(m);

        for (int i = 0; i < m; ++i) {
            for (int j = 0;  j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows[j] = true;
                    cols[i] = true;
                }
            }
        }
        
        //cols
        for (int col = 0; col < n; ++col) {
            if (rows[col]) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][col] = 0;
                }
            }
        }

        //rows
        for (int row = 0; row < m; ++row) {
            if (cols[row]) {
                for (int j = 0; j < n; ++j) {
                    matrix[row][j] = 0;
                }
            }
        }

    }
};