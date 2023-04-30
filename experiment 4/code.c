
#include <stdio.h>
#include <limits.h>

#define MAX 100

void matrixChainOrder(int p[], int n, int m[MAX][MAX], int s[MAX][MAX]) {
    int i, j, k, L, q;
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParentheses(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d ", i);
    } else {
        printf("(");
        printOptimalParentheses(s, i, s[i][j]);
        printOptimalParentheses(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n, i, j;
    int p[MAX], m[MAX][MAX], s[MAX][MAX];

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("Enter the dimensions of the matrices:\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n, m, s);
     printf("\n P= (");
    for (i = 0; i <= n; i++) {
        printf("%d ", p[i]);
        
    }
    printf(")");
    printf("\n");

    
    printf("\nM Table:");
    printf("\n");
    for(int i=n;i>=1;i--)
    {   
        
        for(int j=1;j<=n;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
        
    }

    printf("\nS Table:");
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=n;j++)
        {
            printf("%d\t",s[i][j]);
        }
        printf("\n");
        
    }

    printf("\nOptimal Parenthesization is: ");
    printOptimalParentheses(s, 1, n);

    printf("\nMinimum number of scalar multiplications: %d", m[1][n]);

    return 0;
}
