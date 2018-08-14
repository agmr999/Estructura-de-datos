#include <stdio.h>
#include <stdlib.h>
typedef struct tiponodo tiponodo;

struct tiponodo{
	int dato;
	tiponodo *siguiente;
};

tiponodo *inicio=NULL;
tiponodo *ultimo=NULL;

void insertanod(int dato){
	tiponodo *nuevo=malloc(sizeof(tiponodo));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	if(inicio == NULL){
		inicio=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;
	}
}
void recorrer(){
	tiponodo *aux=inicio;
	while(aux!=NULL){
		printf("%d\n",aux->dato);
		aux=aux->siguiente;
	}
}
void comparar(){
	tiponodo *aux1=inicio;
	tiponodo *aux2=inicio;
	aux1=aux1->siguiente;
	int a=0;
	while(aux2->siguiente!=NULL){
		if((aux1->dato)==(aux2->dato)){
			printf("Hay un numero repetido y es: %d\n",aux1->dato);
			a=1;
		}
		if(aux1->siguiente!=NULL){
			aux1=aux1->siguiente;
		}
		else{
			aux2=aux2->siguiente;
			aux1=aux2->siguiente;
		}
	}
	if(a==0){
		printf("No hay ningun numero repetido\n");	
	}
}

void sea(int a){
	tiponodo *sea= inicio;
	while((a!=sea->dato)&&(sea->siguiente!=NULL)){
		sea=sea->siguiente;	
	}
	if(a==sea->dato){
		printf("El numero si se encuentra dentro de la lista");	
	}else{
		printf("El numero no se encuentra dentro de la lista");
	}
}

void orto(){
	tiponodo *a1=inicio;
	tiponodo *a2=a1->siguiente;
	while((a2!=NULL)&&(a1->dato>=a2->dato)){
		a1=a1->siguiente;	
		a2=a2->siguiente;
		}
	if(a2==NULL){
		printf("\nLa lista esta ordenada de forma descendente");	
	}
	tiponodo *a3=inicio;
	tiponodo *a4=a3->siguiente;
	while((a4!=NULL)&&(a3->dato<=a4->dato)){
		a3=a3->siguiente;	
		a4=a4->siguiente;
	}
	if(a4==NULL){
		printf("\nLa lista esta ordenada de forma ascendente");	
	}
	if((a2!=NULL)&&(a4!=NULL)){
	printf("\nNo esta ordenado");	
	}
}

int main(int argc, char *argv[]) {
	insertanod(1);
	insertanod(2);
	insertanod(3);
	insertanod(4);
	insertanod(5);
	recorrer();
	comparar();
	sea(7);
	orto();
	return 0;
}
