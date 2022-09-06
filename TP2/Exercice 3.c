#include <stdio.h>

float delta(float a, float b, float c) {
    return (b*b) - 4* a * c;
}

int nb_sol(float delta){
    if ( delta < 0){
        return 0;
    }

    if (delta == 0){
        return 1;
    }

    if (delta > 0){
        return 2;
    }
}

float f(float x, float a, float b, float c){
    return (a * x * x) + (b * x) + c;
}

void f_tab(float *X, int nb_val, float a, float b, float c, float *Y){
    for (int i = 0; i < nb_val; i++){
        Y[i] = f(X[i], a, b ,c);
        printf("%.2f\n", Y[i]);
    }
}

void main() {
    float x = 2;
    float a = 2;
    float b = 4;
    float c = 3;
    float d = delta(a, b, c);
    float X[3] = {1, 2, 3};
    float Y[3];
    printf("%.2f \n", d);
    printf("Delta : %d \n", nb_sol(d));
    printf("%f \n", f(x, a, b, c));
    f_tab(&X, 3, a, b, c, &Y);
}


