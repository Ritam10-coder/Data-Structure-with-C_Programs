#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i,j;
	for(i = 0; i < n-1; i++) {
        int min_index = i;
        for(j = i+1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        swap(&arr[min_index], &arr[i]);

        // Print the dataset after every iteration
        int k;
        printf("Iteration %d: ", i + 1);
        for(k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

int main() {
	int i;
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original dataset: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, n);

    printf("Sorted dataset: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
