#include<iostream>
#include<gmpxx.h>

using namespace std;

void checkGCD(mpz_t& n, mpz_t& m){
    mpz_t g, temp;
    mpz_inits(g, temp);

    mpz_sub_ui(temp, m, 1);
    mpz_gcd(g, temp, n);

    if(mpz_cmp_ui(g, 1) > 0){
        cout<<"\nA factor is:";
        mpz_out_str(stdout, 10, g);
        mpz_sub(n, n, n);
    }
}

int main () {
    mpz_t n, c, m;

    // Edit the following line to add your number to be factorised
    mpz_init_set_str(n, "1438671211", 10);
    // Edit the following line to change the value of the base
    mpz_init_set_str(c, "5", 10);
    // Edit the following line to change the value of the maximum cycles
    int max = 1000;

    mpz_init_set(m, c);

    for (int i=1; i <= max; i++){
        mpz_powm_ui(m, m, i, n);
        if(i%10 == 0){
            checkGCD(n, m);
            if (mpz_sgn(n) == 0){
                return 0;
            }
        }
    }
    cout<<"\nNo factor found";
    return 0;
}
