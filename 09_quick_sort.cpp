
#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;    int j = high;
    while(i < j) {
        while(i <= high && arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(int arr[], int low, int high) {
    if(low >= high)
        return;
    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
    return;
}

int main() {
    int n;
    printf("Enter size of array :\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Your sorted array :\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}