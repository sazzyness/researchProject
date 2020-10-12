#include<iostream>
#include<gmpxx.h>

using namespace std;

void Y_LOOP(mpz_t& a, mpz_t& b, mpz_t& cont){
    while (mpz_sgn(a) == 1){
        mpz_sub(a, a, b);
        mpz_add(b, b, cont);
    }
}

int main () {

    mpz_t n, sqrt, ciel, u, v, r, incr, incr2;
    mpz_inits(n, sqrt, ciel, u, v, r, incr, incr2, NULL);

    mpz_set_str(n, "1234", 10);         //number to factorise
    mpz_set_str(incr, "1", 10);
    mpz_set_str(incr2, "2", 10);

    mpz_sqrtrem(sqrt,ciel,n);           //cieling sqrt
    if (mpz_sgn(ciel) != 0){
        mpz_add(sqrt, sqrt, incr);
    }

    mpz_set(u, incr);
    mpz_addmul(u, sqrt, incr2);

    mpz_set(v, incr);

    mpz_mul(r, sqrt, sqrt);
    mpz_sub(r, r, n);

    while (mpz_sgn(r) != 0){            //X_LOOP
        if (mpz_sgn(r) == 1){
            Y_LOOP(r, v, incr2);
        } else if (mpz_sgn(r) == -1){
            mpz_add(r, r, u);
            mpz_add(u, u, incr2);
        }
    }

    mpz_t a, b;                         //finalising
    mpz_init_set(a, u);
    mpz_init_set(b, u);

    mpz_add(a, a, v);
    mpz_sub(a, a, incr2);
    mpz_fdiv_q(a, a, incr2);

    mpz_sub(b, b, v);
    mpz_fdiv_q(b, b, incr2);

    cout<<"\nA factor is:";
    mpz_out_str(stdout, 10, a); //Stream, numerical base, var
    cout<<endl;

    cout<<"Another factor is:";
    mpz_out_str(stdout, 10, b);
    cout<<endl;

    //cin.get();

    return 0;
}
