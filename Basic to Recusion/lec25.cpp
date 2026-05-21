// Maths for DSA 

// to check number of primes from zero to that number n .
/*
Brute force approach can be to run a loop for each number to check
whether its prime or not and that would take O(n**2) but it will do TLE.
SO BETTER TO GO WITH down approach 
*/
// Sieve of Eratoshthenes (Leetcode-> Q.204) 

#include<iostream>
#include<climits>
#include<vector>
using namespace std ;

int countPrimes(int n){
    int count = 0 ;
    vector<bool> vec(n+1 , true) ; // True is alloted for every index (0-50)
    for(int i = 2 ; i < n ; i++){
        if(vec[i]){
            count ++ ;
            for(int j = 2*i ; j < n ; j= j+i){
                vec[j] = false ;
            }
        }
    }
    return count ;
}

// Digits in Number 

void DigitsInNumber(int n){
    int digit , count = 0 , sum = 0;
    while(n != 0){
        digit = n % 10  ;
        count ++ ;
        sum += digit ;
        cout << digit << endl ;
        n /= 10 ; // That makes it complexity O(logn base 10)
    }
    cout << "No. of digits : " << count << endl ;
    cout << "Sum of digits : " << sum << endl ;
}

// Amstrong Number
bool isArmstrong(int n){
    int copy = n ;
    int sum = 0 ;
    while(n != 0){
        int digit = n%10 ;
        sum += (digit*digit*digit) ;
        n /= 10 ;
    }
    return copy==sum ;
}

// Euclids Algorithm for GCD 
int GCD(int a , int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b ;
        }else{
            b = b % a ;
        }
    }
    if(a == 0) return b ;
    return a ;
}

// LCM = product of two numbers / gcd of two numbers 
int LCM(int a , int b){
    int gcd = GCD(a , b) ;
    return (a*b)/gcd ;
}

// Reverse Integer (Leetcode -> Q.7)
int reverseInteger(int n){
    int ans = 0 ;
    while(n != 0){
        int digit = n%10 ;
        // Optimization to check for if revrse of number get out of range of integers.
        if(ans > INT_MAX || ans < INT_MIN){
            return 0 ;
        }
        ans = (ans*10) + digit ;
        n /= 10 ;
    }
    return ans ;
}

// Is Palindrome (Leetcode -> Q.9)
bool isPalindrome(int n){
    int rev = reverseInteger(n) ;
    return rev == n ;
}

int main()
{
    int n = 153 ;
    cout << "No. of primes before " << n << " are = " << countPrimes(n) << endl ;

    DigitsInNumber(n) ;

    if(isArmstrong(n)){
        cout << "Is an Armstrong Number " << endl ;
    }else{
        cout << "Not an Armstrong Number " << endl ;
    }

    int a = 20 , b = 28 ;
    int gcd = GCD( a , b ) ;
    int lcm = LCM( a , b ) ;
    cout << "GCD of " << a << " and " << b << " is : " << gcd << endl ; 
    cout << "LCM of " << a << " and " << b << " is : " << lcm << endl ; 
    
    int x = 1234 ;
    cout << "Reverse of x : " << reverseInteger(x) << endl ;

    int y = 1001 ;
    cout << y << " is palindrome : " << isPalindrome(y) << endl ;
}

/* Modulo Arihtmetics 

if any answer exceeds the integer value then we return its modulo value i.e -> n % (10^7 + 9)

1. (a+b)%m = a%m + b%m
2. (a-b)%m = a%m - b%m
3. (a*b)%m = a%m * b%m

NOTE : (((((a%m)%m)%m)%m)%m) = (a%m)
*/
