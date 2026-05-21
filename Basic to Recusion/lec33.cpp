// Recursion 
/*
    calling a function to itself again & again till the base condition
    we call this as recursion.
*/

#include<iostream>
using namespace std ;

void printToOne(int num){
    // Base case
    if(num== 1){
        cout << "1" << endl ;
        return ;
    }

    cout << num << " " ;
    printToOne(num-1) ;
}

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1) ;
}

int sumOfNum(int n){
    if(n==1){
        return 1 ;
    }
    return (n + sumOfNum(n-1)) ;
}

int main(){
    int num = 8 ;
    printToOne(num) ;
    cout << factorial(5) << endl ;
    cout << sumOfNum(5) << endl ;
}

// Time & Space complexity 
/*
    1. TC --> (i). By reoccurence relation.
             (ii). By Formula 
                    TC = total no. of       *   operations in 
                        recurrence calls         each call
                         
    2. SC --> depth of     *   memory in each call 
              call stack 

*/