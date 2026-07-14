class Solution {
public:
    int solveRec(int m, int n){
        if(m == 1 || n == 1) return 1;
        if(m < 0 || n < 0) return 0;

        int down = solveRec(m-1, n);
        int right = solveRec(m, n-1);

        return down+right;
    }

    int solveMem(int m, int n, vector<vector<int>>&dp){
        if(m == 1 || n == 1) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int down = solveMem(m-1, n, dp);
        int right = solveMem(m, n-1, dp);

        dp[m][n] = down+right;
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        //return solveRec(m, n);

        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solveMem(m,n,dp);
    }
};