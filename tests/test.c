// strasen matrix multiplication printing the count  of no of multiplications and additions

#include <stdio.h>
#include <stdlib.h>

int count = 0;
int count1 = 0;

void add(int **a, int **b, int **c, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            count1++;
        }
    }
}

void sub(int **a, int **b, int **c, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
            count1++;
        }
    }
}

void strassen(int **a, int **b, int **c, int n)
{
    int **p1, **p2, **p3, **p4, **p5, **p6, **p7;
    int **a11, **a12, **a21, **a22;
    int **b11, **b12, **b21, **b22;
    int **c11, **c12, **c21, **c22;
    int **m1, **m2, **m3, **m4, **m5, **m6, **m7;
    int i, j;

    if (n == 2)
    {
        count += 7;
        c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
        c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
        c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
        c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
        return;
    }

    p1 = (int **)malloc(n * sizeof(int *));
    p2 = (int **)malloc(n * sizeof(int *));
    p3 = (int **)malloc(n * sizeof(int *));
    p4 = (int **)malloc(n * sizeof(int *));
    p5 = (int **)malloc(n * sizeof(int *));
    p6 = (int **)malloc(n * sizeof(int *));
    p7 = (int **)malloc(n * sizeof(int *));
    a11 = (int **)malloc(n * sizeof(int *));
    a12 = (int **)malloc(n * sizeof(int *));
    a21 = (int **)malloc(n * sizeof(int *));
    a22 = (int **)malloc(n * sizeof(int *));
    b11 = (int **)malloc(n * sizeof(int *));
    b12 = (int **)malloc(n * sizeof(int *));
    b21 = (int **)malloc(n * sizeof(int *));
    b22 = (int **)malloc(n * sizeof(int *));
    c11 = (int **)malloc(n * sizeof(int *));
    c12 = (int **)malloc(n * sizeof(int *));
    c21 = (int **)malloc(n * sizeof(int *));
    c22 = (int **)malloc(n * sizeof(int *));
    m1 = (int **)malloc(n * sizeof(int *));
    m2 = (int **)malloc(n * sizeof(int *));
    m3 = (int **)malloc(n * sizeof(int *));
    m4 = (int **)malloc(n * sizeof(int *));
    m5 = (int **)malloc(n * sizeof(int *));
    m6 = (int **)malloc(n * sizeof(int *));
    m7 = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        p1[i] = (int *)malloc(n * sizeof(int));
        p2[i] = (int *)malloc(n * sizeof(int));
        p3[i] = (int *)malloc(n * sizeof(int));
        p4[i] = (int *)malloc(n * sizeof(int));
        p5[i] = (int *)malloc(n * sizeof(int));
        p6[i] = (int *)malloc(n * sizeof(int));
        p7[i] = (int *)malloc(n * sizeof(int));
        a11[i] = (int *)malloc(n * sizeof(int));
        a12[i] = (int *)malloc(n * sizeof(int));
        a21[i] = (int *)malloc(n * sizeof(int));
        a22[i] = (int *)malloc(n * sizeof(int));
        b11[i] = (int *)malloc(n * sizeof(int));
        b12[i] = (int *)malloc(n * sizeof(int));
        b21[i] = (int *)malloc(n * sizeof(int));
        b22[i] = (int *)malloc(n * sizeof(int));
        c11[i] = (int *)malloc(n * sizeof(int));
        c12[i] = (int *)malloc(n * sizeof(int));
        c21[i] = (int *)malloc(n * sizeof(int));
        c22[i] = (int *)malloc(n * sizeof(int));
        m1[i] = (int *)malloc(n * sizeof(int));
        m2[i] = (int *)malloc(n * sizeof(int));
        m3[i] = (int *)malloc(n * sizeof(int));
        m4[i] = (int *)malloc(n * sizeof(int));
        m5[i] = (int *)malloc(n * sizeof(int));
        m6[i] = (int *)malloc(n * sizeof(int));
        m7[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n / 2; i++)
    {
        for (j = 0; j < n / 2; j++)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + n / 2];
            a21[i][j] = a[i + n / 2][j];
            a22[i][j] = a[i + n / 2][j + n / 2];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + n / 2];
            b21[i][j] = b[i + n / 2][j];
            b22[i][j] = b[i + n / 2][j + n / 2];
        }
    }

    add(a11, a22, m1, n / 2);
    add(b11, b22, m2, n / 2);
    strassen(m1, m2, p1, n / 2);

    add(a21, a22, m3, n / 2);
    strassen(m3, b11, p2, n / 2);

    sub(b12, b22, m4, n / 2);
    strassen(a11, m4, p3, n / 2);

    sub(b21, b11, m5, n / 2);
    strassen(a22, m5, p4, n / 2);

    add(a11, a12, m6, n / 2);
    strassen(m6, b22, p5, n / 2);

    sub(a21, a11, m7, n / 2);
    add(b11, b12, m1, n / 2);

    strassen(m7, m1, p6, n / 2);

    sub(a12, a22, m7, n / 2);
    add(b21, b22, m1, n / 2);
    strassen(m7, m1, p7, n / 2);

    add(p3, p5, m1, n / 2);
    add(m1, p7, m2, n / 2);
    sub(m2, p4, c12, n / 2);

    add(p1, p4, c11, n / 2);

    add(p2, p4, m1, n / 2);
    add(m1, p6, c21, n / 2);

    add(p1, p3, m1, n / 2);
    add(m1, p5, m2, n / 2);
    sub(m2, p2, c22, n / 2);

    for (i = 0; i < n / 2; i++)
    {
        for (j = 0; j < n / 2; j++)
        {
            c[i][j] = c11[i][j];
            c[i][j + n / 2] = c12[i][j];
            c[i + n / 2][j] = c21[i][j];
            c[i + n / 2][j + n / 2] = c22[i][j];
        }
    }
}

int main()
{
    int n, i, j;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    int **a = (int **)malloc(n * sizeof(int *));
    int **b = (int **)malloc(n * sizeof(int *));
    int **c = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the elements of the first matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    strassen(a, b, c, n);
    printf("The product of the two matrices is: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }


    return 0;
}

