// Pattern Printing

#include<iostream>
using namespace std ;

int main()
{
    /* n = 4 
    1 2 3 4 
    1 2 3 4
    1 2 3 4
    1 2 3 4 
    */

    for (int i = 1 ; i <= 4 ; i++)
    {
        for (int j = 1 ; j <= 4 ; j++)
        {
            cout << j << " " ;
        }cout << endl ;
    }
    cout << endl ;

    /* n = 3
    1 2 3
    4 5 6 
    7 8 9
    */

    int num = 1 ;
    for(int i = 0 ; i < 3 ; i ++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << num << " " ;
            num += 1 ;

        }cout << endl ;
    }cout << endl ;

    /* n = 3
    A B C
    D E F
    G H I
    */

    char ch = 'A' ;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << ch << " " ;
            ch ++ ;
        }cout << endl ;
    }cout << endl ;

    /* n = 4
    *
    **
    ***
    ****
    */

    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j <= i ; j++){
            cout << "* " ;
        }cout << endl ;
    }cout << endl ;

    /* n = 4
        1
        2 2 
        3 3 3 
        4 4 4 4
    */

    int num3 = 1 ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j <= i ; j++){
            cout << num3 << " " ;
        }num3 ++ ;
        cout << endl ;
    }cout << endl ;

    /* n = 4
        A
        B B
        C C C
        D D D D
    */
    char ch2 = 'A' ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j <= i ; j++){
            cout << ch2 << " " ;
        }ch2 ++ ;
        cout << endl ;
    }cout << endl ;
    
    /* n = 4
        1
        1 2 
        1 2 3 
        1 2 3 4
    */

    for(int i = 0 ; i < 4 ; i++){
        int num4 = 1 ;
        for(int j = 0 ; j < i+1 ; j++){
            cout << num4 << " " ;
            num4 ++ ;
        }cout << endl ;
    }cout << endl ;

    /* n = 4
        1
        2 1
        3 2 1
        4 3 2 1
    */

    for(int i = 0 ; i < 4 ; i++){
        for(int j = i+1 ; j > 0 ; j--){
            cout << j << " " ;
        }cout << endl ;
    }cout << endl ;

    /* Floyd's Triangle Pattern 
    1
    2 3
    4 5 6 
    7 8 9 10
    */

    int num2 = 1 ;
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < i+1 ; j++ )
        {
            cout << num2 << " " ;
            num2 ++ ;
        }cout << endl ;
    }cout << endl ;


    /* n = 4
    1 1 1 1
    2 2 2
    3 3
    4
    */
    int num6 = 1 ;

    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4-i ; j++){
            cout << num6 << " " ;
        }num6++ ;
        cout << endl ;
    }cout << endl ;

    /* n = 4 
    1 1 1 1
      2 2 2         ( spaces + numbers )
        3 3 
          4
    */

    int num7 = 1 ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < i ; j++){
            cout << " " ;
        }
        for(int j = 0 ; j < 4-i ; j++){
            cout << num7 ;
        }
        num7++ ;
        cout << endl ;
    }cout << endl ;

    /* Pyramid Pattern (n = 4)
          1
        1 2 1
      1 2 3 2 1 
    1 2 3 4 3 2 1 
    */

    for(int i = 0 ; i < 4 ; i++){
        int num8 = 1 ;
        for(int j = 0 ; j < 4-i-1 ; j++){
            cout << " " ;
        }
        for(int j = 0 ; j < i+1 ; j++){
            cout << num8 ;
            num8++ ;
        }
        for(int j = i ; j > 0 ; j--){
            cout << j ;
        }
        cout << endl ;
    }cout << endl ;

    /* Hollow Diagram Pattern (n = 4)
               *
             *   *
           *       *
         *           *
           *       *
             *   *
               *   
    */

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 4-i-1 ; j > 0 ; j-- ){
            cout << " " ;
        }
        for(int j = 0 ; j < 1 ; j++){
            cout << "*" ;
        }
        for(int j = 0 ; j < (2*i-1) ; j++){
            cout << " " ;
        }

        for(int j = 0 ; j < 1 ; j++){
            if (i!=0){
                cout << "*" ;
            }
        }
        cout << endl ;
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j <= i ; j++){
            cout << " " ;
        }
        for(int j = 0 ; j < 1 ; j++){
            cout << "*" ;
        }
        for(int j = 3-(2*i) ; j > 0 ; j--){
            cout << " " ;
        }
        for(int j = 0 ; j < 1 ; j++){
            if(i!=2){
                cout << "*" ;
            }
        }cout << endl ;
    }

}