#include<iostream>
#include<string>
using namespace std ;

/*
    Encapsulation is wrapping up data members & member function in a single unit 
    called class.
    It helps in data hiding - means its saves sensitive information (by limiting its access).
*/

class account{
    private :
    string password ; // data hiding 
    double balance ;
    public :
    string accountId ;
    string userName ;

};

