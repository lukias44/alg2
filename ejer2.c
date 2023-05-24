#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo {
    int num;
    struct nodo *sig;
} *nodo;

void crearNodo(nodo *p){
	*p = (nodo)malloc(sizeof(struct nodo));
}

bool esVacia(nodo p){
    return (p == NULL);
}           

void apilar(nodo *p, int x) {
    nodo nuevo;
    crearNodo(&nuevo);
    nuevo->num = x;
    nuevo->sig = *p;
    *p = nuevo;
}

int desapilar(nodo *p) {
    if (esVacia(*p)) {
        printf("\nAviso! La pila esta vacia.\n");
        exit(1);
    }
    nodo nodoAEliminar = *p;
    int elementoAEliminar = (*p)->num;
    *p = (*p)->sig;
    free(nodoAEliminar);
    return elementoAEliminar;
}

void mostrar(nodo p){
	printf("\nContenido Pila: ");
	if(!esVacia(p)){
		while(!esVacia(p)){
			printf("[%d] ",p->num);
			p = p->sig;
		}
	} else {
		printf("La pila esta vacia.");
	}
	printf("\n");
}

void clonar(nodo p1, nodo *p2){
	nodo aux = NULL;
	while(p1 != NULL){
		apilar(&aux, p1->num);
		p1 = p1->sig;
	}
	while(aux != NULL){
		apilar(&(*p2), desapilar(&aux));
	}
}

int main() {
	nodo cab1 = NULL, cab2 = NULL;
	int cant = 0, num = 0;

	if(esVacia(cab1)){
		printf("\nAviso! La pila 1 esta vacia.\n");
	} else{
		printf("\nAviso! La pila 1 NO esta vacia.\n");
	}

	if(esVacia(cab2)){
		printf("\nAviso! La pila 2 esta vacia.\n");
	} else{
		printf("\nAviso! La pila 2 NO esta vacia.\n");
	}

	printf("\nDigite cant. de datos a cargar: "); scanf("%d",&cant);
	printf("_________________________________\n");

	for (int i = 0; i < cant; ++i) {
		printf("Digite el (%d) elemento: ",(i+1)); scanf("%d",&num);
		apilar(&cab1, num);
	}

	printf("\nPila Original >");
	mostrar(cab1);

	printf("\nPila Clonada >");
	clonar(cab1, &cab2);
	mostrar(cab2);
	return 0;
}