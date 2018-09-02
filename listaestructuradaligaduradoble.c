#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	int dato;
	struct nodo *siguiente;
	struct nodo *anterior;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;

nodo *crearnodo(int dato){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
	}
	return nuevo;
}

void insertaini(int dato){
	nodo *nuevo=NULL;
	nuevo= crearnodo(dato);
	if(inicio == NULL){
		inicio=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		nuevo->anterior=ultimo;
		ultimo=nuevo;
	}
}

void imprimirFI(){
	nodo *aux=ultimo;
	while(aux!=NULL){
		printf("%d\n",aux->dato);
		aux=aux->anterior;
	}
}

void imprimirIF(){
	nodo *aux=inicio;
	while(aux!=NULL){
		printf("%d\n",aux->dato);
		aux=aux->siguiente;
	}
	imprimirFI();
}


int main(int argc, char *argv[]) {
	insertaini(2);
	insertaini(4);
	insertaini(5);
	imprimirIF();
	return 0;
}

