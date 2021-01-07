#include<iostream>
#include<gmpxx.h>

using namespace std;

int main(){
    mpz_t n, b, t, test, temp;

    // Edit the following line to set the number you want to test
    mpz_init_set_str(n, "2047", 10);
    // Edit the following line to change the base
    mpz_init_set_str(b, "2", 10);

    mpz_inits(test, temp);
    mpz_init_set(t, n);
    mpz_sub_ui(t, t, 1);
    int a = 0;

    while(mpz_even_p(t) != 0){
        mpz_tdiv_q_ui(t, t, 2);
        a++;
    }

    mpz_powm(test, b, t, n);
    mpz_sub_ui(temp, n, 1);
    if (mpz_cmp_ui(test, 1) == 0 || mpz_cmp(test, temp) == 0){
        cout<<"\nn is a strong pseudoprime";
        return 0;
    }
    for (int i = 1; i <= a-1 ; i++){
        mpz_mul(test, test, test);
        mpz_mod(test, test, n);
        if(mpz_cmp(test, temp) == 0){
            cout<<"\nn is a strong pseudoprime";
            return 0;
        }
    }
    cout<<"\nn is not a prime";
    return 0;
}
