/*
1. Calcular el índice de masa corporal ingresando el peso de una persona en kilos y su
estatura en metros. Este índice se obtiene realizando el cociente entre el peso y el
cuadrado de la estatura.
*/

#include <math.h>
#include <stdio.h>

int main(){
    double masaCorporal, peso, estatura;
    printf("Ingrese el peso en kilos: ");
    scanf("%lf", &peso);
    while(peso<=0){
        printf("\nIngrese el peso en kilos: ");
        scanf("%lf", &peso);
    }
    printf("\nIngrese la estatura en metros: ");
    scanf("%lf", &estatura);
    while(estatura<=0){
        printf("\nIngrese la estatura en metros: ");
        scanf("%lf", &estatura);
    }
    masaCorporal=peso/sqrt(estatura);
    printf("\nEl IMC es: %lf",masaCorporal);
}