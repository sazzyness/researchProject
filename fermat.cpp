#include<iostream>
#include<gmpxx.h>

using namespace std;

void Y_LOOP(mpz_t& a, mpz_t& b){
    while (mpz_sgn(a) == 1){
        mpz_sub(a, a, b);
        mpz_add_ui(b, b, 2);
    }
}

int main () {

    mpz_t n, sqrt, ciel, u, v, r;
    mpz_inits(n, sqrt, ciel, u, v, r, NULL);

    // Edit the following line to enter your number to be factorised
    mpz_set_str(n, "12345", 10);        

    mpz_sqrtrem(sqrt,ciel,n);           //cieling sqrt
    if (mpz_sgn(ciel) != 0){
        mpz_add_ui(sqrt, sqrt, 1);
    }

    mpz_set_ui(u, 1);
    mpz_addmul_ui(u, sqrt, 2);

    mpz_set_ui(v, 1);

    mpz_mul(r, sqrt, sqrt);
    mpz_sub(r, r, n);

    while (mpz_sgn(r) != 0){            //X_LOOP

        if (mpz_sgn(r) == 1){
            mpz_init_set(r1, r);
            mpz_init_set(v1, v);

            Y_LOOP(r, v);

        }else if (mpz_sgn(r) == -1){
        mpz_add(r, r, u);
        mpz_add_ui(u, u, 2);
    }
}

mpz_t a, b;                         //finalising
mpz_init_set(a, u);
mpz_init_set(b, u);

mpz_add(a, a, v);
mpz_sub_ui(a, a, 2);
mpz_fdiv_q_ui(a, a, 2);

mpz_sub(b, b, v);
mpz_fdiv_q_ui(b, b, 2);

cout<<"\nA factor is:";
mpz_out_str(stdout, 10, a); //Stream, numerical base, var
cout<<endl;

cout<<"Another factor is:";
mpz_out_str(stdout, 10, b);
cout<<endl;

return 0;
}
