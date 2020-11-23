#include<iostream>

using namespace std;

void sieve(int n){
    bool a[n] ;
    for(int i = 2; i <= n; i++){
        a[i] = true;
    }
    int j = 2 ;

    while(j*j <= n){
        if(a[j]){
            for (int t = j*j; t <= n; t += j){
                a[t] = false;
            }
        }
        j++ ;
    }

    for(int i = 2; i <= n; i++){
        if(a[i]){
            cout << i << " " ;
        }
    }
}

int main() {
    int n = 101;

    cout<<"The primes less than " << n << " are:\n" ;
    sieve(n);

    return 0;
}