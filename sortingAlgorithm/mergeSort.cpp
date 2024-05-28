// merge sort

#include <iostream>
using namespace std;

void merge(int* arr, int left, int mid, int right){
    int n1 = mid - left + 1; // size of first subarray
    int n2 = right - mid; // size of second subarray

    // create temp arrays to hold subarrays
    int leftArr[n1], rightArr[n2];
    
    // copy data to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of leftArr[] if there are any
    while(i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // copy remaining elements of the rightArr[] if there are any
    while(j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
}
void mergeSort(int* arr, int left, int right){
    if(left < right){
        // find the middle point of the subarray
        int mid = left + (right - left) / 2;

        // sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        // merge the sorted halves
        merge(arr, left, mid, right);
    }
  

}

int main() {
  int arr[] = {6, 5, 3, 1, 8, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  mergeSort(arr, 0, n-1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
