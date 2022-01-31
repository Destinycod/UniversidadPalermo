/*
Utilizando estructuras de decision y repeticion resolver:
3. Se ingresan la cantidad de autos vendidos en los últimos 9 años. Calcular y mostrar:
a) El año que se vendieron la mayor cantidad de autos.
b) La cantidad total de autos vendidos
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int autosVendidos,i,masVendidos=0,anioMasVendidos,totalVendidos=0;
    for(i=1;i<10;i++){
        printf("Ingrese la cantidad de autos vendidos el año %d: ", i);
        scanf("%d", &autosVendidos);
        while(autosVendidos<-1){
            printf("Ingrese la cantidad de autos vendidos el año %d: ", i);
            scanf("%d", &autosVendidos);
        }
        totalVendidos=totalVendidos+autosVendidos;
        if(autosVendidos>masVendidos){
            masVendidos=autosVendidos;
            anioMasVendidos=i;
        }
    }
    printf("\nEl año de autos mas vendidos es: %d", anioMasVendidos);
    printf("\nLa cantidad total de autos vendidos es: %d", totalVendidos);
}