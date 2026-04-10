#include <stdio.h>

typedef struct {
    int cost;
    int profit;
    float ratio;
} Project;

// Merge function
void merge(Project arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    Project temp[100];

    while (i <= mid && j <= right) {
        if (arr[i].ratio > arr[j].ratio) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort
void mergeSort(Project arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Greedy selection
void selectProjects(Project arr[], int n, int budget) {
    mergeSort(arr, 0, n - 1);

    float totalProfit = 0.0;

    printf("\nSelected projects:\n");

    for (int i = 0; i < n; i++) {
        if (budget >= arr[i].cost) {
            budget -= arr[i].cost;
            totalProfit += arr[i].profit;
            printf("Project %d selected fully\n", i + 1);
        } else {
            float fraction = (float)budget / arr[i].cost;
            totalProfit += arr[i].profit * fraction;
            printf("Project %d selected %.2f fraction\n", i + 1, fraction);
            break;
        }
    }

    printf("\nTotal Profit = %.2f\n", totalProfit);
}

int main() {
    int n, budget;

    printf("Enter number of projects: ");
    scanf("%d", &n);

    Project arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter profit and cost of project %d: ", i + 1);
        scanf("%d %d", &arr[i].profit, &arr[i].cost);
        arr[i].ratio = (float)arr[i].profit / arr[i].cost;
    }

    printf("Enter total budget: ");
    scanf("%d", &budget);

    selectProjects(arr, n, budget);

    return 0;
}
