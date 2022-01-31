#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int numLegajo;
  char nombre[20];
  char apellido[30];
  int materiasAprobadas;
  struct lista *sig;
}nodo;

void crear(nodo *pt);
void mostrar(nodo *pt);
void generar(nodo *pt, nodo *s);


int main(){
  int i=0;
  nodo *prin=NULL;
  nodo *s=NULL;
  prin=(nodo*)malloc(sizeof(nodo));
  s=(nodo*)malloc(sizeof(nodo));
  crear(prin);
  mostrar(prin);
  generar(prin,s);
  printf("\nLista enlazada con los alumnos que tienen menos de tres materias aprobadas: ");
  mostrar(s);
  
  return 0;
}

void crear(nodo *registro){
  printf("\nIngrese el numero de legajo del alumno: ");
  scanf("%d",registro->numLegajo);
  if(registro->numLegajo==0){
    registro->sig=NULL;
  }
  else{
    printf("\nIngrese el nombre del alumno: ");
    scanf("%s",registro->nombre);
    printf("\nIngrese el apellido del alumno: ");
    scanf("%s",registro->apellido);
    printf("\nIngrese la cantidad de materias aprobadas del alumno: ");
    scanf("%d",registro->materiasAprobadas);
    registro->sig=(nodo*)malloc(sizeof(nodo));
    crear(registro->sig);
  }
}

void mostrar(nodo *registro){
  if(registro->sig!=NULL);{
    printf("%d\n",registro->numLegajo);
    printf("%s\n",registro->nombre);
    printf("%s\n",registro->apellido);
    printf("%d\n",registro->materiasAprobadas);
    mostrar(registro->sig);
  }
  
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