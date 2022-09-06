#include <stdio.h>
#include <math.h>

float delta(float a, float b, float c) {
    return (b*b) - 4* a * c;
}

int nb_sol(float delta, float *x, float *a, float *b, float *c, float *X){
    if ( delta < 0)
        return 0;
    if (delta == 0) {
        return *x = -*b / 2* *a;
    }
    if (delta > 0) {
        X[0] = (-*b - sqrt(delta)) / 2 * *a;
        X[1] = (-*b + sqrt(delta)) / 2 * *a;
        return *X;
    }
}

float f(float x, float a, float b, float c){
    return (a * x * x) + (b * x) + c;
}

void f_tab(float *X, int nb_val, float a, float b, float c, float *Y){
    for (int i = 0; i < nb_val; i++){
        Y[i] = f(X[i], a, b ,c);
    }
}

void main() {
    float x, a = 1, b = 4, c = 1;
    float X[2];
    float Y[2];

    float d = delta(a, b, c);
    int nbr_sol = nb_sol(d, &x, &a, &b, &c, X);

    printf("Delta : %.2f \n", d);
    printf("Solution : %d \n", nbr_sol);

    float function = f(x, a, b, c);
    printf("Resolution : avec x = %.2f est %.2f \n", x, function);

    f_tab(X, 3, a, b, c, Y);
    for(int i = 0; i < 2; i++)
        printf("%.2f\n", Y[i]);
}