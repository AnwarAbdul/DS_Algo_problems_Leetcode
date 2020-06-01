/*
Minimum Path Sum
Solution
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int **dp = (int **)malloc(sizeof(int*)*(m));
        for(int i = 0; i < m; i++)
            dp[i] = (int *)malloc(sizeof(int)*(n));
        int i,j;
        dp[0][0] = grid[0][0];
        int temp;
        for(i = 0; i < m; i++){
            for(j = 0;j < n; j++ ){
                if(i == 0 && j == 0)
                    continue;
                dp[i][j] = -1;
                if(i-1 >= 0){
                    temp = dp[i-1][j] + grid[i][j];
                    if(dp[i][j] == -1)
                        dp[i][j] = temp;
                }
                if(j-1 >= 0){
                    temp = dp[i][j-1] + grid[i][j];
                    if(dp[i][j] == -1)
                        dp[i][j] = temp;
                    else{
                        if(temp < dp[i][j])
                            dp[i][j] = temp;
                    }
                }
            }                        
        }
        int sum = dp[m-1][n-1];
        for(int i = 0; i < m; i++)
            free(dp[i]);
        free(dp);
        return sum;
    }
};