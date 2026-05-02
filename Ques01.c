#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sortArray(arr, n);

    int left = 0, right = n - 1;
    int bestLeft = left, bestRight = right;
    int bestSum = abs(arr[left] + arr[right]);

    while (left < right) {
        int sum = arr[left] + arr[right];
        int absSum = abs(sum);

        if (absSum < bestSum) {
            bestSum = absSum;
            bestLeft = left;
            bestRight = right;
        }

        if (sum < 0)
            left++;       // Sum too negative, move left pointer right
        else if (sum > 0)
            right--;      // Sum too positive, move right pointer left
        else
            break;        // Exact zero found — can't do better
    }

    printf("%d %d\n", arr[bestLeft], arr[bestRight]);
    return 0;
}