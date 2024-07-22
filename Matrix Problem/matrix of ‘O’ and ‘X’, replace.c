void floodFill(char mat[M][N], int x, int y, char prevV, char newV) 
{
    if (x < 0 || x >= M || y < 0 || y >= N) return;
    if (mat[x][y] != prevV) return;
    mat[x][y] = newV;
    floodFill(mat, x+1, y, prevV, newV);
    floodFill(mat, x-1, y, prevV, newV);
    floodFill(mat, x, y+1, prevV, newV);
    floodFill(mat, x, y-1, prevV, newV);
}
void replaceSurrounded(char mat[M][N]) 
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-';
    for (int i = 0; i < M; i++) {
        if (mat[i][0] == '-') floodFill(mat, i, 0, '-', 'O');
        if (mat[i][N-1] == '-') floodFill(mat, i, N-1, '-', 'O');
    }
    for (int j = 0; j < N; j++) {
        if (mat[0][j] == '-') floodFill(mat, 0, j, '-', 'O');
        if (mat[M-1][j] == '-') floodFill(mat, M-1, j, '-', 'O');
    }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
}
void printMatrix(char mat[M][N]) 
{
    for (int i = 0; i < M; i++) 
{
        for (int j = 0; j < N; j++) 
{
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}
