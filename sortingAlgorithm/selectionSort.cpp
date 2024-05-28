// selection sort

#include <iostream>
using namespace std;

void selectionSort(int* arr, int size){
    for (size_t i = 0; i < size -1 ; i++)
    {
        int min_indx = i;
        for (size_t j = i+1; j < size ; j++)
        {
            if(arr[min_indx] > arr[j]){
                min_indx = j;
            }
        }
        swap(arr[min_indx], arr[i]);
        
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

  selectionSort(arr, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
