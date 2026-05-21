// Fibbonacci Number (Leetcode -> Q.509)

#include<iostream>
using namespace std ;

// void fibonacciTerms(int n){
//     int i = 0 ;
//     int j = 1 ;
//     int counter = 2 ; 
//     cout << i << " " ;
//     cout << j << " " ;
//     while(counter < n){
//         int next = i+j ;
//         cout << next << " " ;
//         i= j ;
//         j = next ;
//         counter++ ;
//     }
// }

int nthTerm(int n){  // T.C -> O(2^n) & S.C -> O(n)
    if(n==0 || n==1){
        return n ;
    }
    return nthTerm(n-1) + nthTerm(n-2) ;
}



int main(){
    // int n = 10 ;
    // fibonacciTerms(n) ;
    // cout << endl ;
    int term ;
    cout << "Enter the term of fibbonacci you want to print" << endl ;
    cin >> term ;
    cout << nthTerm(term) ;

}