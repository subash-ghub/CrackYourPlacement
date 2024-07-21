int maxScore(int* cardPoints, int cardPointsSize, int k)
{
    int totalPoints = 0;
    for (int i = 0; i < k; i++) 
    {
        totalPoints += cardPoints[i];
    }
    int maxPoints = totalPoints;
    for (int i = 0; i < k; i++) 
    {
        totalPoints = totalPoints - cardPoints[k - 1 - i] + cardPoints[cardPointsSize - 1 - i];
        if (totalPoints > maxPoints) 
        {
            maxPoints = totalPoints;
        }
    }
    return maxPoints;
}
