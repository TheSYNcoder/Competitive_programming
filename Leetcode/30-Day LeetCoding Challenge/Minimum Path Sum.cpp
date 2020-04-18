class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if ( grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector< vector<int> > dp( rows , vector<int> ( cols , INT_MAX));
        dp[0][0] = grid[0][0];
        for ( int i = 0 ; i < rows ; i ++ ){
            for ( int j = 0 ; j < cols; j ++ ){
                dp[i][j] = min( dp[i][j] , (i - 1 >= 0 ? grid[i][j] + dp[i-1][j] :INT_MAX));
                dp[i][j] = min( dp[i][j] , (j - 1 >= 0 ? grid[i][j] + dp[i][j-1] :INT_MAX));
            }
        }
        return dp[rows-1][cols-1];
    }
};
