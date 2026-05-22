// PQ for Objects 

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Students{
public:
    string name ;
    int marks ;

    Students(string name , int marks){
        this->name = name ;
        this->marks = marks ;
    }

    // Custom Comparator to tell priority queue on which basis it have to compare 
    bool operator < (const Students &obj) const {
        return this->marks < obj.marks ; // If < & < both same inside & outside then its case of "default max heap"
       
        // This will generate in "min Heap" form 
        // return this->marks > obj.marks ;
    }
};

int main(){
    priority_queue<Students> pq;
    pq.push(Students("Aman" , 85)) ;
    pq.push(Students("Bhumika" , 95)) ;
    pq.push(Students("Chetan" , 65)) ;
    
    while(!pq.empty()){
        cout << pq.top().name << " , " << pq.top().marks << endl ;
        pq.pop() ;
    }
}