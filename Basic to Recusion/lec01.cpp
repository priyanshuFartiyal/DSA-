// Arrays and Two Pointer Approach 

#include<iostream>
using namespace std ;

// Linear Search ---

// int linearSearch(int arr[], int n, int key) {
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == key) {
//             return i; // return index if found
//         }
//     }
//     return -1; // return -1 if not found
// }

// int main() {
//     int n, key;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     cout << "Enter element to search: ";
//     cin >> key;

//     int result = linearSearch(arr, n, key);

//     if (result != -1) {
//         cout << "Element found at index " << result << endl;
//     } else {
//         cout << "Element not found!" << endl;
//     }

//     return 0;
// }

 

// Array = { 4 , 2 , 7 , 8 , 1 , 2 , 5 }

void swap(int *x , int *y)
{
    int temp = *x ;
    *x = *y ;
    *y = temp ;
}

// Reverse of Array
void reverse(int arr[] , int size )
{
    for(int i = 0 ; i < size/2 ; i++){
        swap(&arr[i] , &arr[(size-1)-i]) ;
    }
}


int main()
{
    int arr[] = {4 , 2 , 7 , 8 , 1 , 2 , 5} ;
    int size = 7 ;
    reverse(arr, size) ;
    for(int i = 0 ; i<size ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;

    // Two Pointer Approach to Reverse an array 
    int start = 0 , end = size-1 ;
    while(start < end)
    {
        swap(&arr[start] , &arr[end]) ;
        start ++ ;
        end -- ;
    }
    for(int i = 0 ; i<size ; i++){
        cout << arr[i] << " " ;
    }

    
}



