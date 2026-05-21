// Strings 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype> // for func. isalnum() -> isAlphaNumeric
using namespace std ;

int main()
{
    // Character Array
        // char str1[] = {'a' , 'b' , 'c' , '\0' }; // \0 is the null pointer that tells compiler that string ends 
        // cout << str1 << endl ;
        
        // // Better way 
        // char str2[] = "hello" ; // it automatically adds null pointer at end of string 
        // cout << str2 << endl ;

        // // To take input with cin ( only one word )
        // char str3[100] ;
        // cout << "Enter character : " ;
        // cin >> str3 ;
        // cout << "output : " << str3 << endl ;

        // // To take input with cin.getline(str , len , delimiter?)
        // char str4[12] ;
        // cout << "Enter line : " ;
        // cin.getline(str4 , 12 , '%' ) ; // after % no character will be printed in output 
        // cout << "Output : " << str4 << endl ;

        // for(char ch : str4){
        //     cout << ch << " " ;
        // }

    // // String 
    // string str1 = "Apna" ;
    // string str2 = "College" ;
    // string str = str1 + str2 ; // Concatenation
    // cout << str << endl ;
    // cout << (str1 == str2) << endl ; // Comparasion
    // cout << str2.length() << endl ; // Finding length
    // string str3 ;
    // getline(cin , str3) ; // Taking inputs
    // cout << "Output : " << str3 << endl ;
    // for(int i =0 ; i < str.length() ; i++){
    //     cout << str[i] << " " ;
    // }cout << endl ;

    // Reverse String (Leetcode -> Q.344)
    vector<char> str = {'r' , 'a' , 'd' , 'h' , 'a'} ;
    int st = 0 , end = str.size()-1 ;
    while(st < end){
        swap(str[st] , str[end]) ;
        st++ ;
        end-- ;
    }
    for(char ch : str){
        cout << ch << " " ;
    }

    // // Or you can do it with reverse function of STL
    // string str = "Hello" ;
    // reverse(str.begin() , str.end()) ;
    // cout << str << endl ;


}