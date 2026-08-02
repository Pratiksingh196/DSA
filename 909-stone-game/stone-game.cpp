class Solution {
public:
    int solve(vector<int>& piles , int i , int  j,vector<vector<int>>& dp){
        if(i > j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        int alice_from_start = piles[i] + max(solve(piles , i+2 ,j,dp) , solve(piles , i+1 , j-1,dp));
        int alice_from_end = piles[j] + max(solve(piles , i+1 , j-1,dp), solve(piles , i , j-2,dp));

        return dp[i][j] = max(alice_from_start, alice_from_end);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int i = 0 ;
        int j = n-1;
        int sum = 0 ;
        for(int i = 0 ; i< n ; i++){
            sum += piles[i];
        }
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int ans = solve(piles,i,j,dp);

        return (sum/2 < ans);
    }
};