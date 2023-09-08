#include "fatorial.h"
#include <math.h>

int Factorial_recursive(int n){
    // for(int i = 1 ; i < 1000000 ; i++){
    //     sin(i);
    // }

    if(n <= 0)
        return 1;
    else
        return n * Factorial_recursive(n-1);
}

int Factorial_iterative(int n){
    int f = 1;
    while(n > 0){
        f = f * n;
        n = n - 1;
    }
    return f;
}