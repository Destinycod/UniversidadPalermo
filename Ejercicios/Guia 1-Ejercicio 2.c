/* Ingresar el día y la cotización del dólar durante un mes. Calcular y mostrar el día
donde hubo la mayor cotización.
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int i;
    double cotizacionDolar, maximaCotizacion=0;
    char dia[9], maximoDia[9];
    for(i=1;i<31;i++){
        printf("Ingrese la cotización del dólar: ");
        scanf("%lf", &cotizacionDolar);
        while(cotizacionDolar<0){
            printf("Ingrese la cotización del dólar: ");
            scanf("%lf", &cotizacionDolar);
        }
        printf("Ingrese el día: ");
        scanf("%s", dia);
        
        if(cotizacionDolar>maximaCotizacion){
            maximaCotizacion=cotizacionDolar;
            strcpy(maximoDia,dia);
        }
    }
    printf("\nEl día %s el dólar tuvo una cotización máxima de: %lf",maximoDia,maximaCotizacion);
}