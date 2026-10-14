#include <stdio.h>
int b_Search(int arr[], int n, int target) {
    int l = 0;
    int h = n - 1;

    while (l <= h) {

        int mid = l + (h - l) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            l= mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[]={5,24,26,24,34,54,65,74,84,99};

    int n = sizeof(arr) / sizeof(arr[0]);
    int target=65;

    int result = b_Search(arr, n, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}
