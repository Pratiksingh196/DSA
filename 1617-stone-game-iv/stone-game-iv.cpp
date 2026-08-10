class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        if(n <= 0) return 0;
        for(int i=1 ; i*i<=n ; i++){
            if(solve(n-i*i,dp)==0) return dp[n]=1;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(100001,-1);
        return solve(n,dp);
    }
};