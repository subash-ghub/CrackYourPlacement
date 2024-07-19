int numDecodings(const char *s) 
{
    int len = strlen(s);
    if (len == 0) return 0;
    int dp[len + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = (s[0] != '0') ? 1 : 0;
    for (int i = 2; i <= len; i++) 
    {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[len];
}
