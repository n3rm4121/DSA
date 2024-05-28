// C++ program to pass the array as a function and check its size
#include <iostream>
using namespace std;

// Note that arr[] for fun is just a pointer even if square
// brackets are used. It is same as
// void fun(int *arr) or void fun(int arr[size])
void func(int* arr)
{
	cout << "Size of arr[] in func(): " << sizeof(arr) << " bytes";
}

// Drive code
int main()
{
	int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	cout << "Size of arr[] in main(): " << sizeof(arr) << endl;

	func(arr);

	return 0;
}


/*
Output:
Size of arr[] in main(): 32bytes
Size of arr[] in func(): 8 bytes


As we can see,

The size of the arr[] in the main() function (where arr[] is declared) is 32 bytes which is = sizeof(int) * 8 = 4 * 8 = 32 bytes.
But in the function where the arr[] is passed as a parameter, the size of arr[] is shown as 8 bytes (which is the size of a pointer in C/C++).

It is due to the fact that the array decays into a pointer after being passed as a parameter. One way to deal with this problem is to pass the size of the array as another parameter to the function.
*/
