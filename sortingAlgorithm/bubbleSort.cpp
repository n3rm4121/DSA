// bubble sort

#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size)
{

    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            // cout << "comparing: " << arr[i] << " " << arr[j] << endl;
            if (arr[j] < arr[i])
            {
                //cout << "swapping: " << arr[i] << " and " << arr[j] << endl;
                swap(arr[i], arr[j]);
            }
        }
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

  bubbleSort(arr, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
