#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, budget;

    // Input number of projects
    printf("Enter number of projects: ");
    scanf("%d", &n);

    int cost[n], profit[n];

    // Input costs
    printf("Enter project costs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    // Input profits
    printf("Enter project profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    // Input budget
    printf("Enter total budget: ");
    scanf("%d", &budget);

    // DP Table
    int dp[n + 1][budget + 1];

    // Initialize table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= budget; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (cost[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - cost[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Maximum profit
    printf("\nMaximum Profit: %d\n", dp[n][budget]);

    // Backtracking to find selected projects
    int w = budget;
    printf("Selected Projects (1-based index): ");

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= cost[i - 1];
        }
    }

    printf("\n");

    return 0;
}