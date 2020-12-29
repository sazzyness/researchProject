#include<iostream>
#include<gmpxx.h>

using namespace std;

bool debug = false;

void Y_LOOP(mpz_t& a, mpz_t& b){
    if (debug) {
        cout<<"\nEntered Y_LOOP";
    }
    while (mpz_sgn(a) == 1){
        mpz_sub(a, a, b);
        mpz_add_ui(b, b, 2);
    }
}

int main () {

    mpz_t n, sqrt, ciel, u, v, r;
    mpz_inits(n, sqrt, ciel, u, v, r, NULL);

    mpz_set_str(n, "1234", 10);         //number to factorise

    mpz_sqrtrem(sqrt,ciel,n);           //cieling sqrt
    if (mpz_sgn(ciel) != 0){
        mpz_add_ui(sqrt, sqrt, 1);
    }
    if (debug) {
        if (mpz_cmp(sqrt, n) == 0){
            cout<<"\nSquare root not found! :(";
        } else if (mpz_cmp(sqrt, n) < 0){
            cout<<"\nSquare root found";
            mpz_out_str(stdout, 10, sqrt);
        }
    }

    mpz_set_ui(u, 1);
    mpz_addmul_ui(u, sqrt, 2);

    mpz_set_ui(v, 1);

    mpz_mul(r, sqrt, sqrt);
    mpz_sub(r, r, n);

    while (mpz_sgn(r) != 0){            //X_LOOP
        if (debug) {
            cout<<"\nEntered X_LOOP";
        }

        if (mpz_sgn(r) == 1){
            mpz_t r1, v1;           //values to check debug
            mpz_init_set(r1, r);
            mpz_init_set(v1, v);

            Y_LOOP(r, v);

            if (debug) {
                if (mpz_cmp(r1, r) == 0){
                    cout<<"\nr value unchanged :(";
                } else if (mpz_cmp(r1, r) != 0){
                    cout<<"\nr value changed :)";
                } else if (mpz_cmp(v1, v) == 0){
                    cout<<"\nv value unchanged :(";
                } else if (mpz_cmp(v1, v) != 0){
                    cout<<"\nv value changed :)";
                }
            }

        }else if (mpz_sgn(r) == -1){
        mpz_add(r, r, u);
        mpz_add_ui(u, u, 2);
    }
}

mpz_t a, b;                         //finalising
mpz_init_set(a, u);
mpz_init_set(b, u);

if (debug) {
cout<<"\nCalculating final values";
}

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

//cin.get();

return 0;
}
