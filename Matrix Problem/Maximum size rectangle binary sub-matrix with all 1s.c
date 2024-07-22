int maxHist(int row[], int C) 
{
    int result = 0; 
    int top;  
    int area = 0; 
    int i = 0;
    int stack[C];
    int stack_top = -1;
    while (i < C) 
{
        if (stack_top == -1 || row[stack[stack_top]] <= row[i]) {
            stack[++stack_top] = i++;
        }
        else {
            top = stack[stack_top--];
            area = row[top] * (stack_top == -1 ? i : i - stack[stack_top] - 1);
            result = max(area, result);
        }
    }
    while (stack_top != -1) {
        top = stack[stack_top--];
        area = row[top] * (stack_top == -1 ? i : i - stack[stack_top] - 1);
        result = max(area, result);
    }
    return result;
}
int maxRectangle(int A[][4], int R, int C) {
    int result = maxHist(A[0], C);
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // if A[i][j] is 1 then add A[i-1][j]
            if (A[i][j]) A[i][j] += A[i-1][j];
        }
        result = max(result, maxHist(A[i], C));
    }
    return result;
}
