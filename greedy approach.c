#include <stdio.h>

// Structure for project
struct Project {
    int cost;
    int profit;
    float ratio;
};

// Function to sort projects by ratio (descending)
void sortProjects(struct Project p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].ratio < p[j + 1].ratio) {
                struct Project temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, budget;

    printf("Enter number of projects: ");
    scanf("%d", &n);

    struct Project p[n];

    printf("Enter project costs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].cost);
    }

    printf("Enter project profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].profit);
        p[i].ratio = (float)p[i].profit / p[i].cost;
    }

    printf("Enter total budget: ");
    scanf("%d", &budget);

    // Sort by ratio
    sortProjects(p, n);

    int totalProfit = 0;

    printf("\nSelected Projects (Greedy):\n");

    for (int i = 0; i < n; i++) {
        if (budget >= p[i].cost) {
            printf("Cost: %d, Profit: %d\n", p[i].cost, p[i].profit);
            budget -= p[i].cost;
            totalProfit += p[i].profit;
        }
    }

    printf("\nTotal Profit (Greedy): %d\n", totalProfit);

    return 0;
}
