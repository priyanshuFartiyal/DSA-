// Min Stack (beautiful Question Leetcode -> 155)

#include<iostream>
#include<stack>
using namespace std ;

/* // Approach 1 -> less optimized 
class minStack{
    stack<pair<int,int>> s ;
    public:
    void push(int val){
        if(s.empty()){
            s.push({val , val}) ;
        }else{
            if(val > s.top().second){
                s.push({val , s.top().second}) ;
            }else{
                s.push({val , val});
            }
        }
    }

    void pop(){
        if(!s.empty()){
            s.pop() ;
        }
    }

    int top(){
        return s.top().first ;
    }

    int getMin(){
        return s.top().second ;
    }
}; */

// Approach 2 -> more optimized .
class minStack{
    public:
    int minVal ;
    stack<int> s ;

    void push(int val){
        if(s.empty()){
            s.push(val) ;
            minVal = val ;
        }else{
            if(val < minVal){   
                s.push(2*val - minVal ) ; // important formula to get min val after poping the min element
                minVal = val ;
            }else{
                s.push(val) ;
            }
        }
            
    }
    
    void pop(){
        if(s.top() < minVal){ // the modified val that changed minVal will always be less then minVal 
            minVal = 2*minVal - s.top() ; // decode the previous minVal again from formula
        }
        s.pop() ;
    }

    int top(){
        if(s.top() < minVal){
            return minVal ;
        }
        return s.top() ;
    }

    int getMin(){
        return minVal ;
    }
};

int main(){
    minStack S ;
    S.push(-2) ;
    S.push(0) ;
    S.push(-3) ;
    S.push(-4) ;
    cout << "Min ele = "<< S.getMin() << endl ;
    S.pop() ;
    cout << "Top = " << S.top() << endl ;
    S.push(4) ;
    S.push(5) ;
    cout << "Min ele = " << S.getMin() << endl ;

}