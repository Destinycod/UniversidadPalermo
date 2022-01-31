#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Compiler version gcc  6.3.0
/*Crear una lista simplemente enlazada con el 
número de legajo, nombre y apellido y cantidad 
de materias aprobadas de los alumnos de una 
facultad. La carga de datos finaliza cuando 
el número de legajo es igual a cero. 

• Mostrar la lista. 

• Mostrar cuántos alumnos tiene más de 10 
materias aprobadas. 

• Generar una nueva lista con aquellos alumnos 
que tiene menos de 3 materias aprobadas.
*/

typedef struct lista{
  int numLegajo;
  char nombre[20];
  char apellido[30];
  int materiasAprobadas;
  struct lista *sig;
}nodo;

void crear(nodo *pt);
void mostrar(nodo *pt);
int masDe10(nodo *pt);
void generar(nodo *pt, nodo *s);


int main(){
  int i=0, cont;
  nodo *prin=NULL;
  nodo *s=NULL;
  prin=(nodo*)malloc(sizeof(nodo));
  s=(nodo*)malloc(sizeof(nodo));
  crear(prin);
  mostrar(prin);
  cont=masDe10(prin);
  printf("\nLa cantidad de alumnos que tienen mas de diez materias aprobadas: ",cont);
  
  generar(prin,s);
  printf("\nLista enlazada con los alumnos que tienen menos de tres materias aprobadas: ");
  printf("\n");
  mostrar(s);
  
  return 0;
}

void crear(nodo *registro){
  printf("\nIngrese el numero de legajo del alumno: ");
  scanf("%d",&registro->numLegajo);
  if(registro->numLegajo==0){
    registro->sig=NULL;
  }
  else{
    printf("\nIngrese el nombre del alumno: ");
    scanf("%s",registro->nombre);
    printf("\nIngrese el apellido del alumno: ");
    scanf("%s",registro->apellido);
    printf("\nIngrese la cantidad de materias aprobadas del alumno: ");
    scanf("%d",&registro->materiasAprobadas);
    registro->sig=(nodo*)malloc(sizeof(nodo));
    crear(registro->sig);
  }
}

void mostrar(nodo *registro){
  if(registro->sig!=NULL);{
    if(registro->numLegajo!=0){
      printf("\n%d, ",registro->numLegajo);
      printf("%s ",registro->nombre);
      printf("%s, ",registro->apellido);
      printf("%d ",registro->materiasAprobadas);
      mostrar(registro->sig);
    }
  }
  
}

int masDe10(nodo *registro){
  int cont=0;
  while(registro->sig!=NULL);{
    if(registro->materiasAprobadas>10){
      cont++;
     // registro->sig=(nodo*)malloc(sizeof(nodo));
    }
    registro=registro->sig;
  }
  return cont;
}

void generar(nodo *r, nodo *n){
  while(r->sig!=NULL){
    if(r->materiasAprobadas<3){
      n->numLegajo=r->numLegajo;
      strcpy(n->nombre,r->nombre);
      strcpy(n->apellido,r->apellido);
      n->materiasAprobadas=r->materiasAprobadas;
      n->sig=(nodo*)malloc(sizeof(nodo));
      n=n->sig;
    }
    r=r->sig;
  }
  n->sig=NULL;
}

