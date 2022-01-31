#include <stdio.h>
#include <stdlib.h>

/*Desarrollar un programa en C que permita 
crear una lista simplemente enlazada 
con la siguiente información de una 
universidad:

Legajo
Edad
Cantidad de materias cursadas
Cantidad de materias aprobadas.
La carga finaliza con cero en el legajo.

Generar un archivo con aquellos alumnos con 
más del 50% de materias aprobadas.
Mostrarlo en pantalla.*/

typedef struct lista{
  int numLegajo;
  int edad;
  int materiasCursadas;
  int materiasAprobadas;
  struct lista *sig;
}nodo;


void crear(nodo *registro){
  /*FILE *p;
  if((p=fopen("archivo.txt","w"))==NULL)
  printf("\nNo se puede abrir el archivo");
  else{*/
    printf("\nIngrese el numero de legajo del alumno: ");
    scanf("%d",&registro->numLegajo);
    if(registro->numLegajo==0){
      registro->sig=NULL;
    }
    else{
      printf("\nIngrese la edad del alumno: ");
      scanf("%d",&registro->edad);
      printf("\nIngrese la cantidad de materias cursadas del alumno: ");
      scanf("%d",&registro->materiasCursadas);
      printf("\nIngrese la cantidad de materias aprobadas del alumno: ");
      scanf("%d",&registro->materiasAprobadas);
      registro->sig=(nodo*)malloc(sizeof(nodo));
      crear(registro->sig);
    }
  /*}
  fclose(p);*/
}

void mostrar(nodo *registro){
  
  if(registro->sig!=NULL){
    if(registro->numLegajo!=0){
      printf("\n%d, ",registro->numLegajo);
      printf("%d, ",registro->edad);
      printf("%d, ",registro->materiasCursadas);
      printf("%d ",registro->materiasAprobadas);
      mostrar(registro->sig);
    }
  }  
}

void mas50(nodo *registro){
  int porcentaje=0;
  FILE *p;
  //p=fopen("archivo.txt","w");
  if((p=fopen("archivo.txt","w"))==NULL)
  printf("\nNo se puede abrir el archivo");
  else{
    while(registro->sig!=NULL){
      porcentaje=registro->materiasAprobadas*100/registro->materiasCursadas;
      if(porcentaje>50){
        fprintf(p,"%d, %d\n",registro->numLegajo,registro->edad);
      }
      
      registro=registro->sig;
    }
  
  }
  fclose(p);
}


int main(){
  nodo *prin;
  prin=(nodo *)malloc(sizeof(nodo));
  //FILE *p;
  
  printf("CARGA DE DATOS");
  crear(prin);
  printf("\n--------------");
  printf("\nMUESTRA DE DATOS");
  mostrar(prin);
  printf("\n--------------");
  printf("ALUMNOS CON MAS DEL 50% DE MATERIAS APROBADAS");
  mas50(prin);
  
  return 0;
}
