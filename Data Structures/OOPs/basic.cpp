#include<iostream>
#include<vector>
using namespace std ;

/* 
    Object = any entity of real world.
    Class = bluprint for these entities.
    Acess Modifier
        private : data & methods accesible inside class only.
        public : data & methods accesible to everyone.
        protected : data & methods accesible inside class & to its derived classes.
*/

class Teacher {
    private:
    double salary ;
    public:
    // properties / attributes / data members
    string name ;
    string dept ;
    string subject ;

    // Methods / Member function
    void changeDept(string newDept){
        dept = newDept ;
    }
    void setSalary(double s){
        salary = s ;
    }
    void getSalary(void){
        cout << "Salary = " << salary << endl ;
    }

};

int main(){
    Teacher t1 ;
    t1.name = "Rahul" ;
    t1.dept = "CSE" ;
    cout << t1.dept << endl ;
    t1.subject = "OOPs" ;
    t1.setSalary(75000) ;
    t1.getSalary() ;
    t1.changeDept("ECE") ;
    cout << t1.dept << endl ;
}