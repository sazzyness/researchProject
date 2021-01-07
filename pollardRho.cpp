#include<iostream>
#include<gmpxx.h>

using namespace std;

void checkGCD(mpz_t& n, mpz_t& product, mpz_t& incr){
    mpz_t g;
    mpz_init(g);
    mpz_gcd(g, n, product);
    if(mpz_cmp(g, incr) > 0){
        cout<<"\nA factor is:";
        mpz_out_str(stdout, 10, g);
        mpz_sub(n, n, n);
    }
}

void reset(mpz_t& x1, mpz_t& x2, int& range, mpz_t& n, mpz_t& c){
    mpz_set(x1, x2);
    range = 2*range;
    for(int j = 1; j <= range; j++){
        mpz_mul(x2, x2, x2);
        mpz_add(x2, x2, c);
        mpz_mod(x2, x2, n);
    }
}

int main () {
    mpz_t n, c, max, x1, x2, product, terms, incr, temp, base;

   // Edit the following line to add your number to be factorised
    mpz_init_set_str(n, "1438671211", 10);
    mpz_init_set_str(incr, "1", 10);
    // Edit the following line to change the value of c
    mpz_init_set_ui(c, 1);
    // Edit the following line to change the maximum number of cycles
    mpz_init_set_str(max, "1000", 10);
    mpz_init_set_str(x1, "2", 10);
    mpz_init_set_str(x2, "4", 10);
    mpz_add(x2, x2, c);
    mpz_init_set(product, incr);
    mpz_init_set_str(terms, "0", 10);
    mpz_init_set_str(base, "10", 10);
    mpz_init(temp);

    int range = 1;

    while( mpz_cmp(terms, max) <= 0){
        for (int j=1; j <= range; j++){
            mpz_mul(x2, x2, x2);
            mpz_add(x2, x2, c);
            mpz_mod(x2, x2, n);

            mpz_sub(temp, x1, x2);
            mpz_mod(temp, temp, n);
            mpz_mul(product, product, temp);

            mpz_add(terms, terms, incr);

            mpz_mod(temp, terms, base);

            if(mpz_sgn(temp) == 0){
                checkGCD(n, product, incr);
                if (mpz_sgn(n) == 0){
                    return 0;
                }
            }
        }
        reset(x1, x2, range, n, c);
    }
    cout<<"\nNo factor found";
    return 0;
}

