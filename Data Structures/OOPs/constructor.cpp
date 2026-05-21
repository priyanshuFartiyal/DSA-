#include<iostream>
using namespace std ;

/*
    Constructor is a special public method invoked automatically at time of object
     declared.
    It doesn't have return type (it don't need it).
    memory allocation happen when constructor is called.
*/

// Non-parameterized Constructor
class Teacher1 {
    private :
    string name ;
    string dept ;
    public :
    Teacher1(){
        dept = "CSE" ;
        cout << "Department = " << dept << endl ;
    }

};

// Parameterized Constructor
class Teacher2 {
    private :
    string name ;
    string dept ;
    public :
    Teacher2(string naam){
        name = naam ;
        cout << "name = " << name << endl ;
    }
};

// This Pointer
class Teacher3 {
    private :
    string name ;
    string dept ;
    public :
    Teacher3(string name){
        this->name = name ;
        cout << "name = " << name << endl ;
    }
};


int main(){
    Teacher1 obj;
    Teacher2 obj2("Rekha") ;
    Teacher3 obj3("Rahul") ;

    
}