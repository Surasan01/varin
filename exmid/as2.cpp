#include <iostream>

using namespace std;
// Merge
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

// Function median
float findMedian(int arr[], int n) {
    mergeSort(arr, 0, n - 1); // เรียกใช้ Merge Sort แยก

    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        return arr[n / 2];
    }
}

// Function mode
int findMode(int arr[], int n) {
    int f[100] = {0};
    int maxf = 0;
    int i;
    int mode;
    for (i=0;i<n;i++){
        f[arr[i]]++;
    }
    mode = arr[0];
    maxf = f[arr[0]];
    for (i=1;i<n;i++){
        if(f[arr[i]]>maxf){
            maxf = f[arr[i]];
            mode = arr[i];
        }
    }
    return mode;
}

int main(){
    int data[] = {3, 1, 7, 9, 3, 7, 7, 7, 9, 0, 2, 6, 9, 4, 3, 5, 8, 8, 5, 4, 5, 1, 0, 3, 6, 2, 9, 1, 2, 8, 4, 4, 6, 2, 3, 7, 5, 8, 5, 4, 0, 1, 1, 8, 6, 0, 2, 6, 7, 0, 9, 5, 4, 1, 8, 0, 5, 8, 3, 7, 3, 5, 0, 7, 9, 8, 5, 8, 0, 1, 7, 7, 5, 6, 4, 5, 4, 2};
    int n;
    n = sizeof(data) / sizeof(data[0]); // คำนวณจำนวนขนาดdata

    cout << "Median: " << findMedian(data, n) << endl;
    cout << "Mode: " << findMode(data, n) << endl;

    return 0;
}
