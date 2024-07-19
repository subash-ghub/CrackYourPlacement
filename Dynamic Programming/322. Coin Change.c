int coinChange(int coins[], int numCoins, int amount) 
{
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) 
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) 
    {
        for (int j = 0; j < numCoins; j++) 
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) 
            {
                dp[i] = dp[i - coins[j]] + 1 < dp[i] ? dp[i - coins[j]] + 1 : dp[i];
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

