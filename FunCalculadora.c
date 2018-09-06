#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;
typedef struct listadoble listadoble;

struct nodo{
	long dato;
	struct nodo *siguiente;
	struct nodo *anterior;
};

struct listadoble{
	nodo *inicio;
	nodo *final;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;
nodo *inicio2=NULL;
nodo *ultimo2=NULL;
nodo *inicio3=NULL;
nodo *ultimo3=NULL;
nodo *inicio4=NULL;
nodo *ultimo4=NULL;
nodo *inicio5=NULL;
nodo *ultimo5=NULL;

nodo *crearnodo(long dato){
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
	nodo *nuevo = crearnodo(dato);
	if(inicio == NULL){
		inicio=nuevo;
		ultimo=nuevo;
	}
	else{
		nuevo->siguiente=inicio;
		inicio->anterior=nuevo;
		inicio=nuevo;
	}
}



void insertaini2(int dato){
	nodo *nuevo = crearnodo(dato);
	if(inicio2 == NULL){
		inicio2=nuevo;
		ultimo2=nuevo;
	}
	else{
		nuevo->siguiente=inicio2;
		inicio2->anterior=nuevo;
		inicio2=nuevo;
	}
}

void imprimirFI(){
	nodo *aux=ultimo;
	while(aux!=NULL){
		printf("%ld\n",aux->dato);
		aux=aux->anterior;
	}
}

void imprimirIF(){
	nodo *aux=inicio;
	while(aux!=NULL){
		printf("%ld",aux->dato);
		aux=aux->siguiente;
	}
}

void imprimirIF2(){
	nodo *aux=inicio2;
	while(aux!=NULL){
		printf("%ld",aux->dato);
		aux=aux->siguiente;
	}
}

void imprimirIF3(){
	nodo *aux=inicio3;
	while(aux!=NULL){
		printf("%ld",aux->dato);
		aux=aux->siguiente;
	}
}

void imprimirIF4(){
	nodo *aux=inicio4;
	while(aux!=NULL){
		printf("%ld",aux->dato);
		aux=aux->siguiente;
	}
}

void imprimirIF5(){
	nodo *aux=inicio5;
	while(aux!=NULL){
		printf("%ld",aux->dato);
		aux=aux->siguiente;
	}
}


void insertarInicio(int dato){
	nodo *nuevo = crearnodo(dato);
	if(inicio3==NULL){
		inicio3 = nuevo;
		ultimo3 = nuevo;
	}else{
		nuevo->siguiente = inicio3;
		inicio3->anterior = nuevo;
		inicio3 = nuevo;
	}
}

void insertarInicioRes(int dato){
	nodo *nuevo = crearnodo(dato);
	if(inicio4==NULL){
		inicio4 = nuevo;
		ultimo4 = nuevo;
	}else{
		nuevo->siguiente = inicio4;
		inicio4->anterior = nuevo;
		inicio4 = nuevo;
	}
}

void insertarInicioMult(int dato){
	nodo *nuevo = crearnodo(dato);
	if(inicio5==NULL){
		inicio5 = nuevo;
		ultimo5 = nuevo;
	}else{
		nuevo->siguiente = inicio5;
		inicio5->anterior = nuevo;
		inicio5 = nuevo;
	}
}


void suma(){
	int suma,acarreo;
	nodo *aux1 = ultimo;
	nodo *aux2 = ultimo2;
	acarreo=0;
	int	digito = 0;
	while((aux1!=NULL)&&(aux2!=NULL)){
		suma = aux1->dato+aux2->dato+acarreo;
		acarreo = suma/10;
		digito = suma%10;
		insertarInicio(digito);
		aux1 = aux1->anterior;
		aux2 = aux2->anterior;
	}
	nodo *temp = aux1==NULL?aux2:aux1;
	while(temp!=NULL){
		suma = temp->dato+acarreo;
		acarreo = suma/10;
		digito = suma%10;
		insertarInicio(digito);
		temp = temp->anterior;
	}
	if(acarreo>0){
		insertarInicio(acarreo);
	}
}

void resta(){
	int res1=0,res2=0;
	int mul=1;
	nodo *aux1 = ultimo;
	nodo *aux2 = ultimo2;
	while(aux1!=NULL){
	res1=(aux1->dato*mul)+res1; 
	mul*=10;
	aux1=aux1->anterior;
	}
	mul=1;
	while(aux2!=NULL){
		res2=(aux2->dato*mul)+res2; 
		mul*=10;
		aux2=aux2->anterior;
	}
	printf("%i",res1-res2);
}

void multip(int dato){
	for(int i=0;i<dato;i++){
		insertarInicioMult(10);
	}
}

void multiplicar(){
	int acarreo=0,acarreos=0,digito,multi;
	nodo *aux2=ultimo2;
	int a2=0;
	while(aux2!=NULL){
		nodo *aux1=ultimo;
		nodo *aux3=ultimo5;
		acarreo=0;
		acarreos=0;
		for(int ac=0;ac<a2;ac++){
			aux3=aux3->anterior;	
		}
		while(aux1!=NULL){
			multi=(aux1->dato*aux2->dato)+acarreo;
			acarreo = multi/10;
			digito = multi%10;
			if(aux3->dato==10){
				aux3->dato=(aux3->dato-10)+digito;
			}
			else{
				aux3->dato=aux3->dato+digito+acarreos;
				acarreos=aux3->dato/10;
				aux3->dato=aux3->dato%10;
			}
			aux3=aux3->anterior;
			aux1 = aux1->anterior;
		}
		if(acarreo>0){
			aux3->dato=(aux3->dato-10)+acarreo;	
		}
		aux2=aux2->anterior;
		a2+=1;	
	}
}

void divi(){
		float div1=0,div2=0;
	int mul=1;
	nodo *aux1 = ultimo;
	nodo *aux2 = ultimo2;
	while(aux1!=NULL){
		div1=(aux1->dato*mul)+div1; 
		mul*=10;
		aux1=aux1->anterior;
	}
	mul=1;
	while(aux2!=NULL){
		div2=(aux2->dato*mul)+div2; 
		mul*=10;
		aux2=aux2->anterior;
	}
	printf("%.2f",div1/div2);
}

int main(int argc, char *argv[]) {
	int dig,con=0;
	long a,b;
	printf("Ingresa tu primer numero\n");
	scanf("%ld",&a);
	printf("Ingresa tu segundo numero\n");
	scanf("%ld",&b);
	while(a>1){
		dig=a%10;
		a/=10;
		insertaini(dig);
		con++;
	}
	while(b>1){
		dig=b%10;
		b/=10;
		insertaini2(dig);
		con++;
	}
	printf("Suma: ");
	suma();
	imprimirIF3();
	printf("\n\nResta: ");
	resta();
	printf("\n \nMultiplicacion: ");
	multip(con);
	multiplicar();
	imprimirIF5();
	printf("\n\nDivicion: ");
	divi();
	return 0;
}
