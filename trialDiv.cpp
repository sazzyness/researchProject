#include<iostream>
#include<gmpxx.h>

using namespace std;

void divide(mpz_t n, mpz_t max){
    mpz_t f;
    mpz_init_set(f, n);


    mpz_t p[200];
    for (auto & i : p) {
        mpz_init(i);
    }
    int e[200];
    int i = 0;

    for(int d =2; d<= 3; d++){
        if(mpz_divisible_ui_p(f,d) != 0){
            i++;
            mpz_set_ui(p[i], d);
            e[i] = 1;
            mpz_divexact_ui(f, f, d);
            while(mpz_divisible_ui_p(f,d) != 0){
                e[i]++;
                mpz_divexact_ui(f, f, d);
            }
        }
    }

    int d = 5;
    int add = 2;
    while((mpz_cmp_ui(max, d) >= 0) && (mpz_cmp_ui(f, d*d) >= 0)){
        if(mpz_divisible_ui_p(f,d) != 0){
            i++;
            mpz_set_ui(p[i], d);
            e[i] = 1;
            mpz_divexact_ui(f, f, d);
            while(mpz_divisible_ui_p(f,d) != 0){
                e[i]++;
                mpz_divexact_ui(f, f, d);
            }
        }
        d += add;
        add = 6 - add;
    }

    if(mpz_cmp_ui(f, d*d) < 0){
        i++;
        mpz_set(p[i], f);
        e[i] = 1;
        mpz_set_ui(f, 1);
    }

    //output
    for(int r = 1; r<=i; r++){
        cout << p[i] << "^" << e[i] << " * ";
    }
}

int main(){
    mpz_t n, max;
    mpz_inits(n, max, NULL);

    mpz_set_str(n, "100", 10);
    mpz_set_str(max, "10", 10);

    cout << "The factors of ";
    mpz_out_str(stdout, 10, n);
    cout << " are:\n";
    divide(n, max);

    return 0;
}