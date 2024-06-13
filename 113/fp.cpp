#include <cmath>
#include <iostream>

using namespace std;

double calculateEuclideanDistance(double lat1, double lon1, double lat2, double lon2) {
   return round(sqrt(pow(lat1 - lat2, 2) + pow(lon1 - lon2, 2)), 2);
}

void merge(double arr[][5], int left[], int leftSize, int right[], int rightSize) {
   int i = 0, j = 0, k = 0;
   while (i < leftSize && j < rightSize) {
       if (left[i] < right[j]) {
           arr[k][4] = left[i];
           i++;
       } else {
           arr[k][4] = right[j];
           j++;
       }
       k++;
   }

   while (i < leftSize) {
       arr[k][4] = left[i];
       i++;
       k++;
   }

   while (j < rightSize) {
       arr[k][4] = right[j];
       j++;
       k++;
   }
}

void mergeSort(double arr[][5], int size) {
   if (size < 2) {
       return;
   }

   int mid = size / 2;
   int left[mid];
   int right[size - mid];

   for (int i = 0; i < mid; i++) {
       left[i] = arr[i][4];
   }

   for (int i = mid; i < size; i++) {
       right[i - mid] = arr[i][4];
   }

   mergeSort(arr, mid);
   mergeSort(arr, size - mid);

   merge(arr, left, mid, right, size - mid);
}

void calculateKNN(double arr[][5], int size, double lat, double lon) {
   for (int i = 0; i < size; i++) {
       arr[i][4] = calculateEuclideanDistance(arr[i][1], arr[i][2], lat, lon);
   }
   mergeSort(arr, size);
}

string hasYes(double arr[][5], int size, int n = 0) {
   if (n >= 2) {
       return "Yes";
   } else if (size == 0) {
       return "No";
   } else if (arr[0][3] == 1) {
       return hasYes(arr, size - 1, n + 1);
   } else {
       return hasYes(arr, size - 1, n);
   }
}

int main() {
   const int size = 15;
   double data[size][5] = {
       {1, 54, 97, 1},
       {2, 99, 91, 0},
       {3, 61, 53, 1},
       {4, 43, 95, 0},
       {5, 60, 10, 1},
       {6, 40, 74, 0},
       {7, 16, 92, 1},
       {8, 8, 8, 0},
       {9, 90, 37, 1},
       {10, 13, 32, 0},
       {11, 85, 75, 1},
       {12, 98, 23, 0},
       {13, 94, 74, 1},
       {14, 54, 38, 0},
       {15, 36, 42, 1}
   };

   double lat = 52, lon = 25;

   calculateKNN(data, size, lat, lon);
   string result = hasYes(data, 3);

   cout << "Result: " << result << endl;

   return 0;
}