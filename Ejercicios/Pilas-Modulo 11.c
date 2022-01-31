#include <stdio.h>
#include <stdlib.h>

//Compiler version gcc  6.3.0
/*Desarrollar un programa en C que permita 
cargar un pila de n números enteros. 
Calcular y mostrar (en una función) el 
promedio de los cuatro primeros números 
ingresados a la pila. Si no los hubiera, 
mostrar un cartel aclaratorio.*/
//desapilar y cuando queden los ultimos 4 numeros, sumarlos y mostrar el promedio

typedef struct tiponodo{
  int dato;
  struct tiponodo *siguiente;
}nodo;

void mostrar(nodo aux, int *acum, int cont){
    //printf("\nEl cont en funcion mostrar es %d", *cont);
    if (cont<=4){
        *acum=*acum+aux.dato;
        cont=cont-1;
        
    }
    printf("%d \n",aux.dato);
    //printf("\nEl acum es: %d",*acum);
}

nodo* crear_nodo(int dato){
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato=dato;

   u->siguiente=NULL;

   return u;
}

void apilar(nodo** p, nodo* u){
  printf("apilar_nodo\n");
  u->siguiente = *p;
  printf("%02d p=%X u=%X\n", u->dato, *p, u);
  *p = u;
}

nodo desapilar(nodo** p){
  nodo* aux;
    nodo datos;

  datos=**p;
  aux=*p;
  *p=(*p)->siguiente;
  free(aux);
    return datos;
}


int main(){
  int i, num, n, *acum=0, acum1;
  nodo *p=NULL;
  p=(nodo*)malloc(sizeof(nodo));
  
  printf("Ingerese la cantidad de numeros a cargar: ");
  scanf("%d", &n);
  
  for(i=0; i<n; i++){
     printf("\nIngrese un numero: ");
     scanf("%d",&num);
     apilar(&p, crear_nodo(num));
   }
    //printf("\ntamaño de la lista: %d", n); 
    int cont=n;
    while(p!=NULL){
      /*printf("\nValor del contador: %d", cont);
      printf("\n");*/
      mostrar(desapilar(&p),&acum,cont);
   }
    /*printf("\nEl contador es %d ",cont);
    printf("\ny el acumulador es %d:",acum);*/
    acum1=acum;
    if(cont>0)
        printf("\nEl promedio es: %d",acum1/cont);//INVALIDO
    else
        printf("\nNo se puede calcular el promedio");

  return 0;
}



