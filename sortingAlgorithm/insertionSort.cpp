// insertion sort

#include <iostream>
using namespace std;

void insertionSort(int* arr, int size){

    for (size_t i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i -1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

  insertionSort(arr, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
