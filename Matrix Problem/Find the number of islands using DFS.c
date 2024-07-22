int countIslands(int mat[ROW][COL]) 
{
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j) 
        {
            if (mat[i][j] == 1 && !visited[i][j]) 
            {
                DFS(mat, visited, i, j);
                ++count;
            }
        }
    }
    return count;
}
