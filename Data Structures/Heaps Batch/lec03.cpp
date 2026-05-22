// Heaps implementation by vector

#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;
    public:

    void push(int val){
        // push val in vector
        vec.push_back(val);

        // fix the heap if required
        int chdI = vec.size()-1 ;
        int parI = (chdI-1)/2 ;

        while(parI >= 0 && vec[parI] < vec[chdI]){
            swap(vec[chdI] , vec[parI]) ;
            chdI = parI ;
            parI = (chdI-1)/2 ;
        }
    }

    void heapify(int i){

        int l = 2*i + 1 ;
        int r = 2*i + 2 ;

        int maxI = i ;
        if(l < vec.size() && vec[l] > vec[maxI]){
            maxI = l;
        }
        if(r < vec.size() && vec[r] > vec[maxI]){
            maxI = r;
        }

        if(maxI != i){
            swap(vec[maxI] , vec[i]) ;
            heapify(maxI) ;
        }

    }

    void pop(){
        if(vec.empty()) return;

        // Step 1 : swap element with last element 
        swap(vec[0] , vec[vec.size()-1]) ;

        // Step 2 : delete the last node ( which has to be deleted )
        vec.pop_back() ;

        // Step 3 : fix the heap structure 
        heapify(0);
    }

    int top(){
        if(!vec.empty()){
            return vec[0] ;
        }else{
            return -1 ;
        }
    }

    bool empty(){
        return vec.size() == 0 ;
    }

};

int main(){

    Heap heap ;
    heap.push(10) ;
    heap.push(5) ;
    heap.push(100) ;
    heap.push(60) ;

    cout << "Top : " << heap.top() << endl << endl ;

    while(!heap.empty()){
        cout << "Top : " << heap.top() << endl ;
        heap.pop() ;
    }
    
}